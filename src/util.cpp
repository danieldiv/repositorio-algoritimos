#include "util.hpp"

Util::Util() {}
Util::~Util() {}

/**
 * @brief recebe um texto e tokeniza pelo delimitador,
 * fazendo a impressao de cada token
 *
 * @param text
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