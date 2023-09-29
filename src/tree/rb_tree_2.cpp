#include "tree/rb_tree_2.h"

void RB_Tree_2::deleteRecursive(NO_RB *no) {
	if (no != nullptr) {
		deleteRecursive(no->esq);
		deleteRecursive(no->dir);
		delete no;
	}
}

void RB_Tree_2::insert(Record_RB_2 reg) {
	NO_RB *newNo = new NO_RB(reg);
	NO_RB *aux = this->root;
	NO_RB *pai = nullptr;

	while (aux != nullptr) {
		pai = aux;
		if (reg.key < aux->reg.key)
			aux = aux->esq;
		else
			aux = aux->dir;
	}

	newNo->pai = pai;

	if (pai == nullptr)
		this->root = newNo;
	else if (reg.key < pai->reg.key)
		pai->esq = newNo;
	else
		pai->dir = newNo;

	insertFixUp(newNo);
}

void RB_Tree_2::insertFixUp(NO_RB *no) {
	while (no != nullptr && no->pai != nullptr && no->pai->color == RED) {
		if (no->pai == no->pai->pai->esq) {
			NO_RB *tio = no->pai->pai->dir;
			//case 1
			if (tio != nullptr && tio->color == RED) {
				no->pai->color = BLACK;
				tio->color = BLACK;
				no->pai->pai->color = RED;
				no = no->pai->pai;
			} else {
				//case 2
				if (no == no->pai->dir) {
					no = no->pai;
					rotacaoEsquerda(no);
				}
				//case 3
				no->pai->color = BLACK;
				no->pai->pai->color = RED;
				rotacaoDireita(no->pai->pai);
			}
		} else {
			NO_RB *tio = no->pai->pai->esq;
			if (tio != nullptr && tio->color == RED) {
				//case 1
				no->pai->color = BLACK;
				tio->color = BLACK;
				no->pai->pai->color = RED;
				no = no->pai->pai;
			} else {
				//case 2
				if (no == no->pai->esq) {
					no = no->pai;
					rotacaoDireita(no);
				}
				//case 3
				no->pai->color = BLACK;
				no->pai->pai->color = RED;
				rotacaoEsquerda(no->pai->pai);
			}
		}
	}
	this->root->color = BLACK;
}

void RB_Tree_2::rotacaoEsquerda(NO_RB *no) {
	NO_RB *aux;
	aux = no->dir;
	no->dir = aux->esq;
	if (aux->esq != nullptr)
		aux->esq->pai = no;
	aux->pai = no->pai;
	if (no->pai == nullptr)
		this->root = aux;
	else if (no == no->pai->esq)
		no->pai->esq = aux;
	else if (no == no->pai->dir)
		no->pai->dir = aux;
	aux->esq = no;
	no->pai = aux;
}

void RB_Tree_2::rotacaoDireita(NO_RB *no) {
	NO_RB *aux;
	aux = no->esq;
	no->esq = aux->dir;
	if (aux->dir != nullptr)
		aux->dir->pai = no;
	aux->pai = no->pai;
	if (no->pai == nullptr)
		this->root = aux;
	else if (no == no->pai->dir)
		no->pai->dir = aux;
	else if (no == no->pai->esq)
		no->pai->esq = aux;
	aux->dir = no;
	no->pai = aux;
}

void RB_Tree_2::preOrdemRecorsive(NO_RB *no) {
	if (no != nullptr && no->reg.key != -1) {
		cout << no->reg.key << " ";
		preOrdemRecorsive(no->esq);
		preOrdemRecorsive(no->dir);
	}
}

void RB_Tree_2::centralRecorsive(NO_RB *no) {
	if (no != nullptr) {
		centralRecorsive(no->esq);
		cout << no->reg.key << " ";
		centralRecorsive(no->dir);
	}
}

void RB_Tree_2::posOrdemRecorsive(NO_RB *no) {
	if (no != nullptr) {
		posOrdemRecorsive(no->esq);
		posOrdemRecorsive(no->dir);
		cout << no->reg.key << " ";
	}
}

void RB_Tree_2::preOrdem() {
	cout << "Pre Ordem { ";
	preOrdemRecorsive(root);
	cout << "}" << endl;
}

void RB_Tree_2::central() {
	cout << "Central   { ";
	centralRecorsive(root);
	cout << "}" << endl;
}

void RB_Tree_2::posOrdem() {
	cout << "Recursive { ";
	posOrdemRecorsive(root);
	cout << "}" << endl;
}

