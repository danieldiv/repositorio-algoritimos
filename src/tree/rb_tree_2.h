#ifndef RB_TREE_2_H
#define RB_TREE_2_H

#include <iostream>
#include <memory>

using namespace std;

enum Color { RED, BLACK };

class Record_RB_2 {
public:
	int key;
	int value;

	Record_RB_2() {}
	Record_RB_2(int key) :key(key), value(0) {}
	Record_RB_2(int key, int value) :key(key), value(value) {}
	~Record_RB_2() {}
};

class NO_RB {
public:
	NO_RB *esq;
	NO_RB *dir;
	NO_RB *pai;
	Color color;
	Record_RB_2 reg;

	NO_RB(Record_RB_2 reg) :
		esq(nullptr),
		dir(nullptr),
		pai(nullptr),
		color(RED), reg(reg) {}
	~NO_RB() {}
};

class RB_Tree_2 {
private:
	NO_RB *root;

	void insertFixUp(NO_RB *no);
	void rotacaoEsquerda(NO_RB *no);
	void rotacaoDireita(NO_RB *no);

	void preOrdemRecorsive(NO_RB *no);
	void centralRecorsive(NO_RB *no);
	void posOrdemRecorsive(NO_RB *no);
	void deleteRecursive(NO_RB *no);
public:
	RB_Tree_2() { this->root = nullptr; }
	~RB_Tree_2() { this->deleteRecursive(this->root); }

	void insert(Record_RB_2 reg);

	void preOrdem();
	void central();
	void posOrdem();
};

#endif