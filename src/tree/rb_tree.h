#ifndef RB_TREE_H
#define RB_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  Record_RB Record_RB;

struct Record_RB {
	int value;
	double key;
};

enum type { black, red };

typedef struct  TreeRB TreeRB;

struct TreeRB {
	enum type color;
	Record_RB reg;

	TreeRB *LC;
	TreeRB *RC;
	TreeRB *P;
};

void inicializaTreeRB(TreeRB **root);

TreeRB *tree_successor(TreeRB *aux_succ);

void rotacaoEsquerda(TreeRB **root, TreeRB *item);
void rotacaoDireita(TreeRB **root, TreeRB *item);
void fix_insert(TreeRB **root, TreeRB *aux);
void insertItemRB(TreeRB **root, Record_RB r);

void rb_insert(TreeRB **root, TreeRB *x, TreeRB *y, TreeRB *temp);

void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x);
void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w);
void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild);

void searchRB(TreeRB *aux, Record_RB z, double *quant);
void search_delete(TreeRB **root, TreeRB *aux, Record_RB z);

void preordemRB(TreeRB *aux);
void centralRB(TreeRB *aux);
void posordemRB(TreeRB *aux);

#endif