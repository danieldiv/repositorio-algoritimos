#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NO_Huffman {
private:
	size_t frequencia_;
	std::string palavra_;
	NO_Huffman *esquerda_;
	NO_Huffman *direita_;
public:
	NO_Huffman(std::string palavra, size_t frequencia)
		: palavra_(palavra), frequencia_(frequencia) {}
	~NO_Huffman() {}

	static bool compara(NO_Huffman *a, NO_Huffman *b) {
		return a->getFrequencia() < b->getFrequencia();
	}

	void setEsquerda(NO_Huffman *no) { esquerda_ = no; }
	void setDireita(NO_Huffman *no) { direita_ = no; }

	size_t getFrequencia() { return frequencia_; }
	std::string getPalavra() { return palavra_; }

	NO_Huffman *getEsquerda() { return esquerda_; }
	NO_Huffman *getDireita() { return direita_; }

};

class Huffman_Tree {
private:
	std::vector<NO_Huffman *> filaPrioridade_;
	NO_Huffman *raiz_;

	void preOrdem(NO_Huffman *no);
	void posOrdem(NO_Huffman *no);
	void central(NO_Huffman *no);
public:
	Huffman_Tree() {}
	~Huffman_Tree();

	void insere(NO_Huffman *no);
	void constroi();
	void imprime();
};

#endif