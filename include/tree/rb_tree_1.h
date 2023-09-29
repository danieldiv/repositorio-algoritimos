#ifndef RB_TREE_1_H
#define RB_TREE_1_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  Record_RB_1 Record_RB_1;

struct Record_RB_1 {
	int value;
	double key;
};

enum type { black, red };

typedef struct  TreeRB_1 TreeRB_1;

struct TreeRB_1 {
	enum type color;
	Record_RB_1 reg;

	TreeRB_1 *LC;
	TreeRB_1 *RC;
	TreeRB_1 *P;
};

void inicializaTreeRB(TreeRB_1 **root);

TreeRB_1 *tree_successor(TreeRB_1 *aux_succ);

void rotacaoEsquerda(TreeRB_1 **root, TreeRB_1 *item);
void rotacaoDireita(TreeRB_1 **root, TreeRB_1 *item);
void fix_insert(TreeRB_1 **root, TreeRB_1 *aux);
void insertItemRB(TreeRB_1 **root, Record_RB_1 r);

void rb_insert(TreeRB_1 **root, TreeRB_1 *x, TreeRB_1 *y, TreeRB_1 *temp);

void RB_delete(TreeRB_1 **root, TreeRB_1 *z, TreeRB_1 *y, TreeRB_1 *x);
void RB_delete_fix(TreeRB_1 **root, TreeRB_1 *x, TreeRB_1 *w);
void RB_transplant(TreeRB_1 **root, TreeRB_1 *aux, TreeRB_1 *auxchild);

void searchRB(TreeRB_1 *aux, Record_RB_1 z, double *quant);
void search_delete(TreeRB_1 **root, TreeRB_1 *aux, Record_RB_1 z);

void preordemRB(TreeRB_1 *aux);
void centralRB(TreeRB_1 *aux);
void posordemRB(TreeRB_1 *aux);

#endif