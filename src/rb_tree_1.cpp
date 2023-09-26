#include "./tree/rb_tree_1.h"

#include <string.h>

TreeRB_1 *temp, *nill;

/**
 * @brief Prepara a estrutura RB para receber valores
 *
 * @param root ponteiro da estrutura RB
 */
void inicializaTreeRB(TreeRB_1 **root) {
	nill = (TreeRB_1 *)malloc(sizeof(TreeRB_1));
	nill->color = black;
	nill->LC = NULL;
	nill->RC = NULL;
	nill->P = NULL;
	nill->reg.key = 0;
	(*root) = nill;
}

/**
 * @brief Realiza a insercao na estrutura RB
 *
 * @param root ponteiro da estrutura RB
 * @param r valor a ser inserido
 */
void insertItemRB(TreeRB_1 **root, Record_RB_1 r) {
	if ((temp = (TreeRB_1 *)malloc(sizeof(TreeRB_1))) != NULL) {
		temp->P = nill;
		temp->LC = nill;
		temp->RC = nill;
		temp->reg = r;
		temp->color = black;
		rb_insert(root, *root, nill, temp);
	}
}

/**
 * @brief Realiza a rotacao a esquerda
 *
 * @param root ponteiro raiz da estrutura RB
 * @param item ponteiro da estrutura RB
 */
void rotacaoEsquerda(TreeRB_1 **root, TreeRB_1 *item) {
	TreeRB_1 *aux;
	aux = item->RC;
	item->RC = aux->LC;
	if (aux->LC != nill)
		aux->LC->P = item;
	aux->P = item->P;
	if (item->P == nill)
		(*root) = aux;
	else if (item == item->P->LC)
		item->P->LC = aux;
	else if (item == item->P->RC)
		item->P->RC = aux;
	aux->LC = item;
	item->P = aux;
}

/**
 * @brief Realiza a rotacao a direita
 *
 * @param root ponteiro raiz da estrutura RB
 * @param item ponteiro da estrutura RB
 */
void rotacaoDireita(TreeRB_1 **root, TreeRB_1 *item) {
	TreeRB_1 *aux;
	aux = item->LC;
	item->LC = aux->RC;
	if (aux->RC != nill)
		aux->RC->P = item;
	aux->P = item->P;
	if (item->P == nill)
		(*root) = aux;
	else if (item == item->P->RC)
		item->P->RC = aux;
	else if (item == item->P->LC)
		item->P->LC = aux;
	aux->RC = item;
	item->P = aux;
}

/**
 * @brief Balanceia a estrutura RB
 *
 * @param root ponteiro raiz da estrutrua RB
 * @param aux ponteiro auxiliar da estrutura RB
 */
void fix_insert(TreeRB_1 **root, TreeRB_1 *aux) {
	TreeRB_1 *y;
	while (aux->P->color == red) {
		if (aux->P == aux->P->P->LC) {
			y = aux->P->P->RC;
			//case 1
			if (y->color == red) {
				aux->P->color = black;
				y->color = black;
				aux->P->P->color = red;
				aux = aux->P->P;
			} else {
				//case 2
				if (aux == aux->P->RC) {
					aux = aux->P;
					rotacaoEsquerda(root, aux);
				}
				//case 3
				aux->P->color = black;
				aux->P->P->color = red;
				rotacaoDireita(root, aux->P->P);
			}
		} else if (aux->P == aux->P->P->RC) {
			//case 1
			y = aux->P->P->LC;
			if (y->color == red) {
				aux->P->color = black;
				y->color = black;
				aux->P->P->color = red;
				aux = aux->P->P;
			}
			//case 2
			else {
				if (aux == aux->P->LC) {
					aux = aux->P;
					rotacaoDireita(root, aux);
				}
				//case 3
				aux->P->color = black;
				aux->P->P->color = red;
				rotacaoEsquerda(root, aux->P->P);
			}
		}
	}
	(*root)->color = black;
}

/**
 * @brief Insere na estrutura RB
 *
 * @param root ponteiro raiz da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 * @param y ponteiro auxiliar da estrutura RB
 * @param temp ponteiro auxiliar da estrutura RB
 */
void rb_insert(TreeRB_1 **root, TreeRB_1 *x, TreeRB_1 *y, TreeRB_1 *temp) {
	while (x != nill) {
		y = x;
		if (temp->reg.key < x->reg.key)
			x = x->LC;
		else
			x = x->RC;
	}

	temp->P = y;
	if (y == nill)
		(*root) = temp;
	else if (temp->reg.key < y->reg.key)
		y->LC = temp;
	else
		y->RC = temp;
	temp->LC = nill;
	temp->RC = nill;
	temp->color = red;
	fix_insert(root, temp);
}

/**
 * @brief Busca o sucessor
 *
 * @param aux_succ ponteiro auxiliar da estrutura RB
 */
TreeRB_1 *tree_successor(TreeRB_1 *aux_succ) {
	while (aux_succ->LC != nill)
		aux_succ = aux_succ->LC;
	return aux_succ;
}

/**
 * @brief Pesquisa um elemento na estrutura RB
 * @param z valor a ser pesquisa
 * @param quant ponteiro para armazenar a quantidade de pesquisa
 */
void searchRB(TreeRB_1 *aux, Record_RB_1 z, double *quant) {
	while (aux != nill && z.key != aux->reg.key) {
		(*quant)++;
		if (z.key < aux->reg.key)
			aux = aux->LC;
		else
			aux = aux->RC;
	}
}

/**
 * @brief Exclui um elemento da arvore
 *
 * @param root ponteiro da estrutura RB para exclusao
 * @param aux ponteiro da estrutura RB utilizado como pesquisa do elemento
 * @param z valor utilizado para pesquisa
 */
void search_delete(TreeRB_1 **root, TreeRB_1 *aux, Record_RB_1 z) {
	while (aux != nill && z.key != aux->reg.key) {
		if (z.key < aux->reg.key)
			aux = aux->LC;
		else
			aux = aux->RC;
	}
	if (aux->reg.key == z.key) {
		// printf("Node (%lf) found\n", z.key);
		RB_delete(root, aux, aux, aux);
	} else
		printf("Node (%lf) does not exist\n", z.key);
}

/**
 * @brief Balanceia apoz excluir um elemento
 *
 * @param root  ponteiro raiz da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 * @param w ponteiro auxiliar da estrutura RB
 */
void RB_delete_fix(TreeRB_1 **root, TreeRB_1 *x, TreeRB_1 *w) {
	while (x != (*root) && x->color == black) {
		if (x == x->P->LC) {
			w = x->P->RC;
			if (w->color == red) {
				w->color = black;
				x->P->color = red;
				rotacaoEsquerda(root, x->P);
				w = x->P->RC;
			} else if (w->LC->color == black && w->RC->color == black) {
				w->color = red;
				x = x->P;
			} else if (w->RC->color == black) {
				w->LC->color = black;
				w->color = red;
				rotacaoDireita(root, w);
				w = x->P->RC;
			} else {
				w->color = x->P->color;
				x->P->color = black;
				w->RC->color = black;
				rotacaoEsquerda(root, x->P);
				x = (*root);
			}
		} else {
			w = x->P->LC;
			if (w->color == red) {
				w->color = black;
				x->P->color = red;
				rotacaoDireita(root, x->P);
				w = x->P->LC;
			} else if (w->RC->color == black && w->LC->color == black) {
				w->color = red;
				x = x->P;
			} else if (w->LC->color == black) {
				w->RC->color = black;
				w->color = red;
				rotacaoEsquerda(root, w);
				w = x->P->LC;
			} else {
				w->color = x->P->color;
				x->P->color = black;
				w->LC->color = black;
				rotacaoDireita(root, x->P);
				x = (*root);
			}
		}
	}
	x->color = black;
}

/**
 * @brief Remove um valor da estrutura RB
 *
 * @param z ponteiro auxiliar da estrutura RB
 * @param y ponteiro auxiliar da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 */
void RB_delete(TreeRB_1 **root, TreeRB_1 *z, TreeRB_1 *y, TreeRB_1 *x) {
	enum type originalcolor;	//keep track of x which moves into y's original position
	originalcolor = y->color;	//Keep track of original color

	//case 1
	if (z->LC == nill) {
		x = z->RC;
		RB_transplant(root, z, z->RC);
	}
	//case 2
	else if (z->RC == nill) {
		x = z->LC;
		RB_transplant(root, z, z->LC);
	}
	//two cases: z has both Children
	else {
		y = tree_successor(z->RC);
		originalcolor = y->color;
		x = y->RC;

		if (y->P == z) {
			x->P = y;
		}
		//swap subtree of y->RC pointing to y->P (before we move y to z)
		else {
			RB_transplant(root, y, y->RC);
			y->RC = z->RC;		//partial change of y
			y->RC->P = y;
		}
		//replacement of z with y (also builds subtrees)
		RB_transplant(root, z, y);
		y->LC = z->LC;
		y->LC->P = y;
		y->color = z->color;
	}
	//imbalanced RBT only possible when we delete a black node
	if (originalcolor == black)
		RB_delete_fix(root, x, x);
	free(z);
}

/**
 * @brief replace the subtree rooted at node aux with the subtree rooted at aux-LC or aux->RC
 *
 * @param root ponteiro raiz da estrutura RB
 * @param aux ponteiro auxiliar da estrutura RB
 * @param auxchild ponteiro da estrutura RB
 */
void RB_transplant(TreeRB_1 **root, TreeRB_1 *aux, TreeRB_1 *auxchild) {
	if (aux->P == nill)
		(*root) = auxchild;
	else if (aux == aux->P->LC)
		aux->P->LC = auxchild;
	else
		aux->P->RC = auxchild;
	auxchild->P = aux->P;
}

/**
 * @brief imprime a estrutura RB na forma pre ordem
 *
 * @param aux ponteiro da estrutura RB utilizado para impressao
 */
void preordemRB(TreeRB_1 *aux) {
	if (aux != NULL && aux->reg.key != 0) {
		printf("%.0lf ", aux->reg.key);
		preordemRB(aux->LC);
		preordemRB(aux->RC);
	}
}

/**
 * @brief imprime a estrutura RB na forma pre central
 *
 * @param aux ponteiro da estrutura RB utilizado para impressao
 */
void centralRB(TreeRB_1 *aux) {
	if (aux != NULL && aux->reg.key != 0) {
		centralRB(aux->LC);
		printf("%lf ", aux->reg.key);
		centralRB(aux->RC);
	}
}

/**
 * @brief imprime a estrutura RB na forma pos ordem
 *
 * @param aux ponteiro da estrutura RB utilizado para impressao
 */
void posordemRB(TreeRB_1 *aux) {
	if (aux != NULL && aux->reg.key != 0) {
		posordemRB(aux->LC);
		posordemRB(aux->RC);
		printf("%lf ", aux->reg.key);
	}
}