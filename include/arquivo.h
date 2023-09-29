#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "util.h"

#include <fstream>

// teste

class Arquivo {
private:
public:
	Arquivo();
	~Arquivo();

	// C
	void readFile(char *path);
	void createFile();
	void readFileIntervalo(size_t intervalo, char *arquivo);

	// C++
	void readFile(string &path);
	void readFileTokenizando(string &path);
	void createFile(string &path);
};

#endif