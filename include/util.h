#ifndef UTIL_H
#define UTIL_H

#include "class_template.h"

#include <sstream>
#include <string>

#include <string.h>
#include <stdio.h>

#define loopStr(str) for (long unsigned d_inc = 0; d_inc < str.length(); d_inc++)
#define tolowerStr(str) loopStr(str) str[d_inc] = tolower(str[d_inc])

#define VERMELHO "\x1b[31m"
#define VERDE    "\x1b[32m"
#define AZUL     "\x1b[34m"
#define RESET    "\x1b[0m"

#define N 5
#define TAM 3
#define MAX 4

class Util {
private:
public:
	Util();
	~Util();

	// C
	void tokenizar(char *str);
	bool compararString(char *str1, char *str2);
	void mudarCorTerminal();
	void combinacoes(int *vec, int perm[], int index, int n, int k);
	void matrizTridimensional();

	// C++
	void tokenizar(string &text);
	void printMap(map<int, int> &mapeamento);
	void compararString(string &str1, string &str2);
	void combinacoes(vector<int> &vec, int perm[], int index, int n, int k);
	void stringMinuscula();
};

#endif