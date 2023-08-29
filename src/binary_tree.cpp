#include "./include/binary_tree.hpp"

Tree *createTree() {
	return NULL;
}

void insertItem(Tree **t, Record r) {
	if (*t == NULL) {
		*t = (Tree *)malloc(sizeof(Tree));
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

void pesquisa(Tree **t, Tree **aux, Record r) {
	if (*t == NULL) {
		printf("[ERRO]: Node not found!\n");
		return;
	}

	if ((*t)->reg.key < r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key > r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

void antecessor(Tree **t, Tree *aux) {
	if ((*t)->dir != NULL) {
		antecessor(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItem(Tree **t, Record r) {
	Tree *aux;

	if (*t == NULL) {
		printf("[ERROR]: Record not found!!!\n");
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

void preordem(Tree *t) {
	if (!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree *t) {
	if (!(t == NULL)) {
		central(t->esq);
		printf("%d ", t->reg.key);
		central(t->dir);
	}
}

void posordem(Tree *t) {
	if (!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%d ", t->reg.key);
	}
}