#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class NO_Huffman {
private:
	string palavra_;
	size_t frequencia_;
	shared_ptr<NO_Huffman> esquerda_;
	shared_ptr<NO_Huffman> direita_;
public:
	NO_Huffman() {}

	NO_Huffman(string palavra, size_t frequencia)
		: palavra_(palavra), frequencia_(frequencia) {
		esquerda_ = nullptr;
		direita_ = nullptr;
	}
	~NO_Huffman() {}

	static bool compara(shared_ptr<NO_Huffman> a, shared_ptr<NO_Huffman> b) {
		return a->getFrequencia() < b->getFrequencia();
	}

	void setEsquerda(shared_ptr<NO_Huffman> no) { esquerda_ = no; }
	void setDireita(shared_ptr<NO_Huffman> no) { direita_ = no; }

	size_t getFrequencia() { return frequencia_; }
	string getPalavra() { return palavra_; }

	shared_ptr<NO_Huffman> getEsquerda() { return esquerda_; }
	shared_ptr<NO_Huffman> getDireita() { return direita_; }
};

class Huffman_Tree {
private:
	vector<shared_ptr<NO_Huffman>> filaPrioridade_;
	shared_ptr<NO_Huffman> raiz_;
	unordered_map<string, string> codificacao_;

	void preOrdem(shared_ptr<NO_Huffman> no);
	void posOrdem(shared_ptr<NO_Huffman> no);
	void central(shared_ptr<NO_Huffman> no);

	void decode(shared_ptr<NO_Huffman> no, string code);
	void code(shared_ptr<NO_Huffman> no, string code);
public:
	Huffman_Tree() {}
	~Huffman_Tree() {}

	void insere(shared_ptr<NO_Huffman> no);
	void constroi();
	void imprime();

	void decode(string code);
};

#endif