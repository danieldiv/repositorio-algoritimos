#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "util.hpp"

#include <fstream>

class Arquivo {
private:
public:
	Arquivo();
	~Arquivo();

	// C
	void readFile(char *path);
	void createFile();
	void readFileIntervalo(int intervalo, char *arquivo);

	// C++
	void readFile(string path);
	void readFileTokenizando(string path);
	void createFile(string path);
};

#endif