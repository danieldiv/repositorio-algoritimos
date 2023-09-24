#ifndef AVL_TREE_1_H
#define AVL_TREE_1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Record_AVL_1 Record_AVL_1;
typedef struct Tree_AVL_1 Tree_AVL_1;

struct Record_AVL_1 {
	int value;
	int key;
};

struct Tree_AVL_1 {
	Record_AVL_1 item;
	Tree_AVL_1 *esq, *dir;
	int peso;
};

Tree_AVL_1 *createTree_AVL();

void insertItem_AVL(Tree_AVL_1 **t, Record_AVL_1 r);
// void pesquisa(Tree_AVL_1 **t, Tree_AVL_1 **aux, Record_AVL_1 r);

// void antecessor_AVL(Tree_AVL_1 **t, Tree_AVL_1 *aux);
// void rebalancear_AVL(Tree_AVL_1 **t);

void removeItem_AVL(Tree_AVL_1 **t, Tree_AVL_1 **f, Record_AVL_1 item);

void preordem_AVL(Tree_AVL_1 *t);
void central_AVL(Tree_AVL_1 *t);
void posordem_AVL(Tree_AVL_1 *t);

int getPeso(Tree_AVL_1 **t);
int getMaxPeso(int left, int right);

void rotacaoSimplesDireita_AVL(Tree_AVL_1 **t);
void rotacaoSimplesEsquerda_AVL(Tree_AVL_1 **t);
void rotacaoDuplaDireita_AVL(Tree_AVL_1 **t);
void rotacaoDuplaEsquerda_AVL(Tree_AVL_1 **t);

void free_AVL(Tree_AVL_1 *t);

#endif