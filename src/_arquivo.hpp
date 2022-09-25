#ifndef _ARQUIVO_HPP
#define _ARQUIVO_HPP

#include <iostream>

#include "./class/arquivo.hpp"

using namespace std;

void _arquivo();

/**
 * @brief trabalhando com arquivos
 *
 */
void _arquivo() {
	Arquivo r;
	Util u;
	string texto;

	cout << "\nLENDO E ESCREVENDO NO ARQUIVO" << endl << endl;

	char *str = (char *)malloc(sizeof(char) * 100);

	cout << "C" << endl << endl;

	strcpy(str, "text2");
	r.readFile(str);
	r.createFile();

	cout << endl << endl;

	r.readFileIntervalo(11, str);

	cout << endl << "\nC++" << endl << endl;

	texto.assign("text.txt");
	r.readFile(texto);
	r.createFile("newFile.txt");

	cout << "\n======================" << endl << endl;
}

#endif