#ifndef BINARY_TREE_CPLUSPLUS_HPP
#define BINARY_TREE_CPLUSPLUS_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

class RecordClass {
public:
	int value;
	int key;
};

class TreeClass {
public:
	RecordClass reg;
	TreeClass *esq, *dir;

	TreeClass *createTreeClass();
	void insertItemClass(TreeClass **t, RecordClass r);
	void pesquisaClass(TreeClass **t, TreeClass **aux, RecordClass r);

	void antecessorClass(TreeClass **t, TreeClass *aux);
	void removeItemClass(TreeClass **t, RecordClass r);

	void preordemClass(TreeClass *t);
	void centralClass(TreeClass *t);
	void posordemClass(TreeClass *t);
};

#endif