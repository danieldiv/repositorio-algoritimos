#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class NO_Huffman {
private:
	std::string palavra_;
	size_t frequencia_;
	std::shared_ptr<NO_Huffman> esquerda_;
	std::shared_ptr<NO_Huffman> direita_;
public:
	NO_Huffman() {}

	NO_Huffman(std::string palavra, size_t frequencia)
		: palavra_(palavra), frequencia_(frequencia) {
		esquerda_ = nullptr;
		direita_ = nullptr;
	}
	~NO_Huffman() {}

	static bool compara(std::shared_ptr<NO_Huffman> a, std::shared_ptr<NO_Huffman> b) {
		return a->getFrequencia() < b->getFrequencia();
	}

	void setEsquerda(std::shared_ptr<NO_Huffman> no) { esquerda_ = no; }
	void setDireita(std::shared_ptr<NO_Huffman> no) { direita_ = no; }

	size_t getFrequencia() { return frequencia_; }
	std::string getPalavra() { return palavra_; }

	std::shared_ptr<NO_Huffman> getEsquerda() { return esquerda_; }
	std::shared_ptr<NO_Huffman> getDireita() { return direita_; }
};

class Huffman_Tree {
private:
	std::vector<std::shared_ptr<NO_Huffman>> filaPrioridade_;
	std::shared_ptr<NO_Huffman> raiz_;

	void preOrdem(std::shared_ptr<NO_Huffman> no);
	void posOrdem(std::shared_ptr<NO_Huffman> no);
	void central(std::shared_ptr<NO_Huffman> no);
public:
	Huffman_Tree() {}
	~Huffman_Tree() {}

	void insere(std::shared_ptr<NO_Huffman> no);
	void constroi();
	void imprime();
};

#endif