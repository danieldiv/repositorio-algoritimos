#ifndef BINARY_TREE_3_HPP
#define BINARY_TREE_3_HPP

#include <iostream>

using namespace std;

class Record_3 {
public:
	int key;
	int value;

	Record_3() {}
	Record_3(int key) :key(key), value(0) {}
	Record_3(int key, int value) :key(key), value(value) {}
	~Record_3() {}
};

class NO {
public:
	Record_3 reg;
	NO *esq;
	NO *dir;

	NO(Record_3 reg) :esq(nullptr), dir(nullptr), reg(reg) {}
	~NO() { delete esq; delete dir; }
};

class Tree_3 {
private:
	NO *root;
	NO *insertRecord(NO *atual, Record_3 reg);

	void preOrdemRecorsive(NO *atual);
	void centralRecorsive(NO *atual);
	void posOrdemRecorsive(NO *atual);
public:
	Tree_3() { root = nullptr; }
	~Tree_3() { delete root; }

	void insert(Record_3 reg) { root = insertRecord(root, reg); }

	void preOrdem();
	void central();
	void posOrdem();
};

#endif