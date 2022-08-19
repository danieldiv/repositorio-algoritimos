#include "read.hpp"

Read::Read() {}
Read::~Read() {}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 */
void Read::readFile(string path) {
	path.insert(0, "files/");

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line))
			cout << line << endl;
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

/**
 * @brief cria um arquivo e guarda informacoes
 *
 * @param file nome do arquivo a ser criado
 */
void Read::createFile(string path) {
	path.insert(0, "files/");

	ofstream myfile(path);
	string line;

	if (myfile.is_open()) {
		myfile << "dado 1" << endl;
		myfile << "dado 2" << endl;
		myfile << 25 << endl;
		myfile << "dado 4" << 5.7 << " " << true << " " << 99 << " teste" << endl;

		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}