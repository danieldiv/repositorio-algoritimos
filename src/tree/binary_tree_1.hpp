#ifndef BINARY_TREE_1_HPP
#define BINARY_TREE_1_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record_1 Record_1;
typedef struct Tree_1 Tree_1;

struct Record_1 {
	int value;
	int key;
};

struct Tree_1 {
	Record_1 reg;
	Tree_1 *esq, *dir;
};

Tree_1 *createTree();
void insertItem(Tree_1 **t, Record_1 r);
void pesquisa(Tree_1 **t, Tree_1 **aux, Record_1 r);

void antecessor(Tree_1 **t, Tree_1 *aux);
void removeItem(Tree_1 **t, Record_1 r);

void preordem(Tree_1 *t);
void central(Tree_1 *t);
void posordem(Tree_1 *t);

#endif