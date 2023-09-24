#ifndef AVL_TREE_2_HPP
#define AVL_TREE_2_HPP

#include <iostream>
#include <memory>

using namespace std;

class Record_AVL_NO {
public:
	int key;
	int value;

	Record_AVL_NO() {}
	Record_AVL_NO(int key) :key(key), value(0) {}
	Record_AVL_NO(int key, int value) :key(key), value(value) {}
	~Record_AVL_NO() {}
};

class NO_AVL {
public:
	std::shared_ptr<NO_AVL> esq;
	std::shared_ptr<NO_AVL> dir;
	Record_AVL_NO reg;
	int peso;

	NO_AVL(Record_AVL_NO reg) :
		esq(nullptr), dir(nullptr), reg(reg), peso(0) {}
	~NO_AVL() {}
};

class Tree_AVL_2 {
private:
	std::shared_ptr<NO_AVL> root;
	std::shared_ptr<NO_AVL> insertRecord(std::shared_ptr<NO_AVL> no, Record_AVL_NO reg);

	void preOrdemRecorsive(std::shared_ptr<NO_AVL> no);
	void centralRecorsive(std::shared_ptr<NO_AVL> no);
	void posOrdemRecorsive(std::shared_ptr<NO_AVL> no);

	int getPeso(shared_ptr < NO_AVL> no);
	int getMaxPeso(int left, int right);

	shared_ptr<NO_AVL> rotacaoSimplesDireita_AVL(shared_ptr<NO_AVL> no);
	shared_ptr<NO_AVL> rotacaoSimplesEsquerda_AVL(shared_ptr<NO_AVL> no);
	shared_ptr<NO_AVL> rotacaoDuplaDireita_AVL(shared_ptr<NO_AVL> no);
	shared_ptr<NO_AVL> rotacaoDuplaEsquerda_AVL(shared_ptr<NO_AVL> no);
public:
	Tree_AVL_2() { root = nullptr; }
	~Tree_AVL_2() {}

	void insert(Record_AVL_NO reg) { root = insertRecord(root, reg); }

	void preOrdem();
	void central();
	void posOrdem();
};

#endif