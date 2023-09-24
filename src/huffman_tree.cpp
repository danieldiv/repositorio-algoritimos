#include "./tree/huffman_tree.h"

/**
 * @brief insercao na fila de prioridade
 *
 * como a insercao sera feita a partir da ordem central de uma arvore
 * binaria de busca, a insercao sera feita de forma ordenada
 *
 * @param no
 */
void Huffman_Tree::insere(std::shared_ptr<NO_Huffman> no) {
	this->filaPrioridade_.push_back(no);
}

/**
 * @brief constroi a arvore de huffman a partir da fila de prioridade
 *
 * a fila de prioridade deve estar ordenada de forma crescente
 * para que a arvore seja construida corretamente, pois ira pegar
 * os dois primeiros elementos da fila e criar um novo no com a soma
 */
void Huffman_Tree::constroi() {
	while (this->filaPrioridade_.size() > 1) {
		std::shared_ptr<NO_Huffman> x = this->filaPrioridade_[0];
		std::shared_ptr<NO_Huffman> y = this->filaPrioridade_[1];

		auto z = std::make_shared<NO_Huffman>("#", x->getFrequencia() + y->getFrequencia());

		z->setEsquerda(x);
		z->setDireita(y);

		this->filaPrioridade_.erase(this->filaPrioridade_.begin());
		this->filaPrioridade_.erase(this->filaPrioridade_.begin());

		this->insere(z);

		sort(this->filaPrioridade_.begin(), this->filaPrioridade_.end(), NO_Huffman::compara);
	}
	this->raiz_ = this->filaPrioridade_[0];
}

void Huffman_Tree::preOrdem(std::shared_ptr<NO_Huffman> no) {
	if (no != nullptr) {
		if (no->getPalavra() != "#") {
			cout << "[" << no->getPalavra() << " ";
			cout << no->getFrequencia() << "] ";
		}
		this->preOrdem(no->getEsquerda());
		this->preOrdem(no->getDireita());
	}
}

void Huffman_Tree::posOrdem(std::shared_ptr<NO_Huffman> no) {
	if (no != nullptr) {
		this->posOrdem(no->getEsquerda());
		this->posOrdem(no->getDireita());
		if (no->getPalavra() != "#") {
			cout << "[" << no->getPalavra() << " ";
			cout << no->getFrequencia() << "] ";
		}
	}
}

void Huffman_Tree::central(std::shared_ptr<NO_Huffman> no) {
	if (no != nullptr) {
		this->central(no->getEsquerda());
		if (no->getPalavra() != "#") {
			cout << "[" << no->getPalavra() << " ";
			cout << no->getFrequencia() << "] ";
		}
		this->central(no->getDireita());
	}
}

void Huffman_Tree::imprime() {
	this->preOrdem(this->raiz_);
}