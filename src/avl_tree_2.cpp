#include "./tree/avl_tree_2.hpp"

std::shared_ptr<NO_AVL> Tree_AVL_2::insertRecord(std::shared_ptr<NO_AVL> no, Record_AVL_NO reg) {
	if (no == nullptr) return std::make_shared<NO_AVL>(reg);

	if (reg.key < no->reg.key) {
		no->esq = insertRecord(no->esq, reg);

		if (getPeso(no->esq) - getPeso(no->dir) == 2) {
			if (reg.key < no->esq->reg.key)
				return rotacaoSimplesDireita_AVL(no);
			else
				return rotacaoDuplaDireita_AVL(no);
		}
	}
	if (reg.key > no->reg.key) {
		no->dir = insertRecord(no->dir, reg);

		if (getPeso(no->dir) - getPeso(no->esq) == 2) {
			if (reg.key > no->dir->reg.key)
				return rotacaoSimplesEsquerda_AVL(no);
			else
				return rotacaoDuplaEsquerda_AVL(no);
		}
	}
	no->peso = getMaxPeso(getPeso(no->esq), getPeso(no->dir)) + 1;

	return no;
}

void Tree_AVL_2::preOrdemRecorsive(std::shared_ptr<NO_AVL> no) {
	if (no != nullptr) {
		cout << no->reg.key << " ";
		preOrdemRecorsive(no->esq);
		preOrdemRecorsive(no->dir);
	}
}

void Tree_AVL_2::centralRecorsive(std::shared_ptr<NO_AVL> no) {
	if (no != nullptr) {
		centralRecorsive(no->esq);
		cout << no->reg.key << " ";
		centralRecorsive(no->dir);
	}
}

void Tree_AVL_2::posOrdemRecorsive(std::shared_ptr<NO_AVL> no) {
	if (no != nullptr) {
		posOrdemRecorsive(no->esq);
		posOrdemRecorsive(no->dir);
		cout << no->reg.key << " ";
	}
}

void Tree_AVL_2::preOrdem() {
	cout << "Pre Ordem { ";
	preOrdemRecorsive(root);
	cout << "}" << endl;
}

void Tree_AVL_2::central() {
	cout << "Central   { ";
	centralRecorsive(root);
	cout << "}" << endl;
}

void Tree_AVL_2::posOrdem() {
	cout << "Recursive { ";
	posOrdemRecorsive(root);
	cout << "}" << endl;
}

int Tree_AVL_2::getPeso(shared_ptr<NO_AVL> no) {
	return (no == nullptr) ? -1 : no->peso;
}

int Tree_AVL_2::getMaxPeso(int left, int right) {
	return (left > right) ? left : right;
}

shared_ptr<NO_AVL> Tree_AVL_2::rotacaoSimplesDireita_AVL(shared_ptr<NO_AVL> no) {
	auto aux = no->esq;
	no->esq = aux->dir;
	aux->dir = no;
	no->peso = getMaxPeso(getPeso(no->esq), getPeso(no->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(aux->esq), no->peso) + 1;

	return aux;
}

shared_ptr<NO_AVL> Tree_AVL_2::rotacaoSimplesEsquerda_AVL(shared_ptr<NO_AVL> no) {
	auto aux = no->dir;
	no->dir = aux->esq;
	aux->esq = no;
	no->peso = getMaxPeso(getPeso(no->esq), getPeso(no->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(aux->dir), no->peso) + 1;

	return aux;
}

shared_ptr<NO_AVL> Tree_AVL_2::rotacaoDuplaDireita_AVL(shared_ptr<NO_AVL> no) {
	no->esq = rotacaoSimplesEsquerda_AVL(no->esq);
	return rotacaoSimplesDireita_AVL(no);
}

shared_ptr<NO_AVL> Tree_AVL_2::rotacaoDuplaEsquerda_AVL(shared_ptr<NO_AVL> no) {
	no->dir = rotacaoSimplesDireita_AVL(no->dir);
	return rotacaoSimplesEsquerda_AVL(no);
}