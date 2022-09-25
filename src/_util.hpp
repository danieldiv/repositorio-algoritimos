#ifndef _UTIL_HPP
#define _UTIL_HPP

#include "./class/util.hpp"
#include "./class/arquivo.hpp"

void _util();

/**
 * @brief funcoes uteis
 *
 */
void _util() {
	Arquivo r;
	Util u;

	char *str = (char *)malloc(sizeof(char) * 100);
	char *str2 = (char *)malloc(sizeof(char) * 100);

	cout << "COMPARAR STRINGS" << endl << endl;

	strcpy(str, "daniel");
	strcpy(str2, "daniel");

	cout << "C" << endl << endl;
	cout << str << " - " << str2 << " -> ";
	cout << u.compararString(str, str2) << endl;

	strcpy(str2, "alves");

	cout << str << " - " << str2 << " -> ";
	cout << u.compararString(str, str2) << endl;

	string s1, s2, texto;

	s1.assign("teste");
	s2 = "teste";

	cout << "\nC++" << endl << endl;
	u.compararString(s1, s2);

	s1.assign("hello");
	u.compararString(s1, s2);

	cout << "\n======================" << endl << endl;

	cout << "TOKENIZANDO UMA STRING POR VIRGULA" << endl << endl;

	texto = "texto de string,possui,virgulas";
	str = (char *)malloc(sizeof(char) * 100);
	strcpy(str, "texto de char,possui,virgulas");

	cout << "C" << endl << endl;
	u.tokenizar(str);

	cout << "\nC++" << endl << endl;
	u.tokenizar(texto);

	cout << "\n======================" << endl << endl;

	map<int, int> mapeamento;

	mapeamento.insert({ 2,6 });
	mapeamento.insert({ 1,5 });
	mapeamento.insert({ 6,26 });
	mapeamento.insert({ 7,222 });
	mapeamento[66] = 55;
	mapeamento[67] = 555;

	cout << "UTILIZANDO MAP DE FORMA COMUM" << endl << endl;

	u.printMap(mapeamento);

	cout << "\nMODIFICAR COR DA LINHA NO TERMINAL" << endl << endl;

	u.mudarCorTerminal();

	cout << "\n======================" << endl << endl;
}

#endif