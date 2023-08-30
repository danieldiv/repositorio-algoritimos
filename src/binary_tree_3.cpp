#include "./tree/binary_tree_3.hpp"

NO *Tree_3::insertRecord(NO *atual, Record_3 reg) {
	if (atual == nullptr) return new NO(reg);

	if (reg.key < atual->reg.key)
		atual->esq = insertRecord(atual->esq, reg);
	else if (reg.key > atual->reg.key)
		atual->dir = insertRecord(atual->dir, reg);

	return atual;
}

void Tree_3::preOrdemRecorsive(NO *atual) {
	if (atual != nullptr) {
		cout << atual->reg.key << " ";
		preOrdemRecorsive(atual->esq);
		preOrdemRecorsive(atual->dir);
	}
}

void Tree_3::centralRecorsive(NO *atual) {
	if (atual != nullptr) {
		centralRecorsive(atual->esq);
		cout << atual->reg.key << " ";
		centralRecorsive(atual->dir);
	}
}

void Tree_3::posOrdemRecorsive(NO *atual) {
	if (atual != nullptr) {
		posOrdemRecorsive(atual->esq);
		posOrdemRecorsive(atual->dir);
		cout << atual->reg.key << " ";
	}
}

void Tree_3::preOrdem() {
	cout << "Pre Ordem { ";
	preOrdemRecorsive(root);
	cout << "}" << endl;
}

void Tree_3::central() {
	cout << "Central   { ";
	centralRecorsive(root);
	cout << "}" << endl;
}

void Tree_3::posOrdem() {
	cout << "Recursive { ";
	posOrdemRecorsive(root);
	cout << "}" << endl;
}

