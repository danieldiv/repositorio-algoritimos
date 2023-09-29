#ifndef BINARY_TREE_2_H
#define BINARY_TREE_2_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

class Record_2 {
public:
	int value;
	int key;
};

class Tree_2 {
public:
	Record_2 reg;
	Tree_2 *esq, *dir;

	~Tree_2() {}

	Tree_2 *createTreeClass();
	void insertItemClass(Tree_2 **t, Record_2 r);
	void pesquisaClass(Tree_2 **t, Tree_2 **aux, Record_2 r);

	void antecessorClass(Tree_2 **t, Tree_2 *aux);
	void removeItemClass(Tree_2 **t, Record_2 r);
	void freeRaiz_2(Tree_2 *t);

	void preordemClass(Tree_2 *t);
	void centralClass(Tree_2 *t);
	void posordemClass(Tree_2 *t);
};

#endif