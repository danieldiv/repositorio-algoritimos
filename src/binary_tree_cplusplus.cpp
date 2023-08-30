#include "./tree/binary_tree_cplusplus.hpp"

TreeClass *TreeClass::createTreeClass() {
	return NULL;
}

void TreeClass::insertItemClass(TreeClass **t, RecordClass r) {
	if (*t == NULL) {
		*t = (TreeClass *)malloc(sizeof(TreeClass));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
	} else {
		if (r.key < (*t)->reg.key)
			insertItemClass(&(*t)->esq, r);

		if (r.key > (*t)->reg.key)
			insertItemClass(&(*t)->dir, r);
	}

}

void TreeClass::pesquisaClass(TreeClass **t, TreeClass **aux, RecordClass r) {
	if (*t == NULL) {
		printf("[ERRO]: Node not found!\n");
		return;
	}

	if ((*t)->reg.key < r.key) { pesquisaClass(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key > r.key) { pesquisaClass(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void TreeClass::antecessorClass(TreeClass **t, TreeClass *aux) {
	if ((*t)->dir != NULL) {
		antecessorClass(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void TreeClass::removeItemClass(TreeClass **t, RecordClass r) {
	TreeClass *aux;

	if (*t == NULL) {
		printf("[ERROR]: RecordClass not found!!!\n");
		return;
	}

	if ((*t)->reg.key > r.key) { removeItemClass(&(*t)->esq, r); return; }
	if ((*t)->reg.key < r.key) { removeItemClass(&(*t)->dir, r); return; }

	if ((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		return;
	}

	if ((*t)->esq != NULL) {
		antecessorClass(&(*t)->esq, *t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
}

void TreeClass::preordemClass(TreeClass *t) {
	if (!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordemClass(t->esq);
		preordemClass(t->dir);
	}
}

void TreeClass::centralClass(TreeClass *t) {
	if (!(t == NULL)) {
		centralClass(t->esq);
		printf("%d ", t->reg.key);
		centralClass(t->dir);
	}
}

void TreeClass::posordemClass(TreeClass *t) {
	if (!(t == NULL)) {
		posordemClass(t->esq);
		posordemClass(t->dir);
		printf("%d ", t->reg.key);
	}
}