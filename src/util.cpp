#include "util.hpp"

Util::Util() {}
Util::~Util() {}

/**
 * @brief recebe um ponteiro de char e tokeniza
 *
 * @param str
 *
 * utilizada em C
 */
void Util::tokenizar(char *str) {
	const char sep[] = ",";
	char *tokens;

	tokens = strtok(str, sep);

	while (tokens != NULL) {
		printf("%s\n", tokens);
		tokens = strtok(NULL, sep);
	}
}

/**
 * @brief recebe um texto e tokeniza pelo delimitador,
 * fazendo a impressao de cada token
 *
 * @param text
 *
 * utilizada em C++
 */
void Util::tokenizar(string text) {
	char del = ',';

	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del))
		cout << token << endl;
}

/**
 * @brief impressao basica de um map
 *
 * @param mapeamento
 */
void Util::printMap(map<int, int> mapeamento) {
	map<int, int>::iterator itr;

	for (itr = mapeamento.begin(); itr != mapeamento.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
}

/**
 * @brief compara duas string e retorna um booleano
 *
 * @param str1 string 1
 * @param str2 string 2
 * @return true caso as duas string sejam iguais
 * @return false caso as duas string sejam diferentes
 */
bool Util::compararString(char *str1, char *str2) {
	return strcmp(str1, str2) == 0 ? true : false;
}

/**
 * @brief compara duas string e imprime se sao iguais ou diferente
 *
 * @param str1 string 1
 * @param str2 string 2
 */
void Util::compararString(string str1, string str2) {
	cout << str1 << " - " << str2 << " -> ";

	if (str1.compare(str2) == 0)
		cout << "igual" << endl;
	else
		cout << "diferente" << endl;
}