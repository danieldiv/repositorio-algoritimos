#include "./tree/avl_tree_1.hpp"

Tree_AVL_1 *createTree_AVL() { return NULL; }

void insertItem_AVL(Tree_AVL_1 **t, Record_AVL_1 item) {
	if (*t == NULL) {
		*t = (Tree_AVL_1 *)malloc(sizeof(Tree_AVL_1));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->item = item;
		(*t)->peso = 0;
	} else {
		if (item.key < (*t)->item.key) {
			insertItem_AVL(&(*t)->esq, item);

			if (getPeso(&(*t)->esq) - getPeso(&(*t)->dir) == 2) {
				if (item.key < (*t)->esq->item.key)
					rotacaoSimplesDireita_AVL(t);
				else
					rotacaoDuplaDireita_AVL(t);
			}
		}
		if (item.key > (*t)->item.key) {
			insertItem_AVL(&(*t)->dir, item);

			if (getPeso(&(*t)->dir) - getPeso(&(*t)->esq) == 2) {
				if (item.key > (*t)->dir->item.key)
					rotacaoSimplesEsquerda_AVL(t);
				else
					rotacaoDuplaEsquerda_AVL(t);
			}
		}
	}
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
}

void antecessor_AVL(Tree_AVL_1 **t, Tree_AVL_1 *aux) {
	if ((*t)->dir != NULL) {
		antecessor_AVL(&(*t)->dir, aux);
		return;
	}
	aux->item = (*t)->item;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void rebalancear_AVL(Tree_AVL_1 **t) {
	int delta;

	delta = getPeso(&(*t)->esq) - getPeso(&(*t)->dir);

	if (delta == 2) {
		if (getPeso(&(*t)->esq->esq) >= getPeso(&(*t)->esq->dir)) {
			rotacaoSimplesDireita_AVL(t);
		} else {
			rotacaoDuplaDireita_AVL(t);
		}
	} else if (delta == -2) {
		if (getPeso(&(*t)->dir->dir) >= getPeso(&(*t)->dir->esq)) {
			rotacaoSimplesEsquerda_AVL(t);
		} else {
			rotacaoDuplaEsquerda_AVL(t);
		}
	}
}

void preordem_AVL(Tree_AVL_1 *t) {
	if (!(t == NULL)) {
		printf("%d ", t->item.key);
		preordem_AVL(t->esq);
		preordem_AVL(t->dir);
	}
}

void central_AVL(Tree_AVL_1 *t) {
	if (!(t == NULL)) {
		preordem_AVL(t->esq);
		printf("%d ", t->item.key);
		preordem_AVL(t->dir);
	}
}

void posordem_AVL(Tree_AVL_1 *t) {
	if (!(t == NULL)) {
		preordem_AVL(t->esq);
		preordem_AVL(t->dir);
		printf("%d ", t->item.key);
	}
}

int getPeso(Tree_AVL_1 **t) {
	return (*t == NULL) ? -1 : (*t)->peso;
}

int getMaxPeso(int left, int right) {
	return (left > right) ? left : right;
}

void rotacaoSimplesDireita_AVL(Tree_AVL_1 **t) {
	Tree_AVL_1 *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->esq), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoSimplesEsquerda_AVL(Tree_AVL_1 **t) {
	Tree_AVL_1 *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->dir), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoDuplaDireita_AVL(Tree_AVL_1 **t) {
	rotacaoSimplesEsquerda_AVL(&(*t)->esq);
	rotacaoSimplesDireita_AVL(t);
}

void rotacaoDuplaEsquerda_AVL(Tree_AVL_1 **t) {
	rotacaoSimplesDireita_AVL(&(*t)->dir);
	rotacaoSimplesEsquerda_AVL(t);
}

void removeItem_AVL(Tree_AVL_1 **t, Tree_AVL_1 **f, Record_AVL_1 item) {
	Tree_AVL_1 *aux;

	if (*t == NULL) {
		printf("Nao foi possivel encontrar o valor: %d\n", item.key);
		return;
	}

	if (item.key < (*t)->item.key) {
		removeItem_AVL(&(*t)->esq, t, item);
		return;
	}
	if (item.key > (*t)->item.key) {
		removeItem_AVL(&(*t)->dir, t, item);
		return;
	}

	if ((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		rebalancear_AVL(f);
		return;
	}

	if ((*t)->esq != NULL) {
		antecessor_AVL(&(*t)->esq, *t);
		rebalancear_AVL(f);
		rebalancear_AVL(t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
	rebalancear_AVL(f);
	rebalancear_AVL(t);
}

void free_AVL(Tree_AVL_1 *t) {
	if (t != NULL) {
		free_AVL(t->esq);
		free_AVL(t->dir);
		free(t);
	}
}