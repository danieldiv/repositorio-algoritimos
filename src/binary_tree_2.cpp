#include "./tree/binary_tree_2.hpp"

Tree_2 *Tree_2::createTreeClass() {
	return NULL;
}

void Tree_2::insertItemClass(Tree_2 **t, Record_2 r) {
	if (*t == NULL) {
		*t = (Tree_2 *)malloc(sizeof(Tree_2));
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

void Tree_2::pesquisaClass(Tree_2 **t, Tree_2 **aux, Record_2 r) {
	if (*t == NULL) {
		printf("[ERRO]: Node not found!\n");
		return;
	}

	if ((*t)->reg.key < r.key) { pesquisaClass(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key > r.key) { pesquisaClass(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void Tree_2::antecessorClass(Tree_2 **t, Tree_2 *aux) {
	if ((*t)->dir != NULL) {
		antecessorClass(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void Tree_2::removeItemClass(Tree_2 **t, Record_2 r) {
	Tree_2 *aux;

	if (*t == NULL) {
		printf("[ERROR]: Record_2 not found!!!\n");
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

void Tree_2::preordemClass(Tree_2 *t) {
	if (!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordemClass(t->esq);
		preordemClass(t->dir);
	}
}

void Tree_2::centralClass(Tree_2 *t) {
	if (!(t == NULL)) {
		centralClass(t->esq);
		printf("%d ", t->reg.key);
		centralClass(t->dir);
	}
}

void Tree_2::posordemClass(Tree_2 *t) {
	if (!(t == NULL)) {
		posordemClass(t->esq);
		posordemClass(t->dir);
		printf("%d ", t->reg.key);
	}
}