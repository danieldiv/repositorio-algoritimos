#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record {
	int value;
	int key;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
};

Tree *createTree();
void insertItem(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);

void antecessor(Tree **t, Tree *aux);
void removeItem(Tree **t, Record r);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);

#endif