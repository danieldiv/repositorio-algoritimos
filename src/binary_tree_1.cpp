#include "./tree/binary_tree_1.h"

Tree_1 *createTree() {
	return NULL;
}

void freeRaiz_1(Tree_1 *t) {
	if (t != NULL) {
		freeRaiz_1(t->esq);
		freeRaiz_1(t->dir);
		free(t);
	}
}

void insertItem(Tree_1 **t, Record_1 r) {
	if (*t == NULL) {
		*t = (Tree_1 *)malloc(sizeof(Tree_1));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
	} else {
		if (r.key < (*t)->reg.key)
			insertItem(&(*t)->esq, r);

		if (r.key > (*t)->reg.key)
			insertItem(&(*t)->dir, r);
	}
}

void pesquisa(Tree_1 **t, Tree_1 **aux, Record_1 r) {
	if (*t == NULL) {
		printf("[ERRO]: Node not found!\n");
		return;
	}

	if ((*t)->reg.key < r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key > r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void antecessor(Tree_1 **t, Tree_1 *aux) {
	if ((*t)->dir != NULL) {
		antecessor(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItem(Tree_1 **t, Record_1 r) {
	Tree_1 *aux;

	if (*t == NULL) {
		printf("[ERROR]: Record_1 not found!!!\n");
		return;
	}

	if ((*t)->reg.key > r.key) { removeItem(&(*t)->esq, r); return; }
	if ((*t)->reg.key < r.key) { removeItem(&(*t)->dir, r); return; }

	if ((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		return;
	}

	if ((*t)->esq != NULL) {
		antecessor(&(*t)->esq, *t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
}

void preordem(Tree_1 *t) {
	if (!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree_1 *t) {
	if (!(t == NULL)) {
		central(t->esq);
		printf("%d ", t->reg.key);
		central(t->dir);
	}
}

void posordem(Tree_1 *t) {
	if (!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%d ", t->reg.key);
	}
}