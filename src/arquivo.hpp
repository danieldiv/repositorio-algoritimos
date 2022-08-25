#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "util.hpp"

#include <fstream>
#include <stdio.h>

class Arquivo {
private:
public:
	Arquivo();
	~Arquivo();

	// C
	void readFile(char *path);
	void readFile10in10();
	void createFile();

	// C++
	void readFile(string path);
	void createFile(string path);
};

Arquivo::Arquivo() {}
Arquivo::~Arquivo() {}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param path caminho do arquivo
 *
 * utilizada em C
 */
void Arquivo::readFile(char *path) {
	char *str = (char *)malloc(100);
	sprintf(str, "src/files/%s.txt", path);

	FILE *file = fopen(str, "r");

	char *result, linha[100];

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
				printf("%s", linha);
			}
		}
	}
	fclose(file);
}

void Arquivo::readFile10in10() {
	FILE *fp;
	fp = fopen("src/files/text2.txt", "r");

	if (fp == NULL) {
		printf("Nao foi possivel abrir o arquivo 10 in 10\n");
	} else {
		char *teste = (char *)malloc(sizeof(char) * 100);

		// aponta para o fim da ultima linha
		fseek(fp, 0, SEEK_END);

		long int tam;
		long int max = 10; // de quanto em quanto ira caminhar no arquivo
		tam = ftell(fp); // pega a posicao atual 83

		/**
		 * @brief funcionamento
		 *
		 * fseek(fp, 5, SEEK_SET)
		 *
		 * fp -> ponteiro do arquivo
		 * 5 -> posicao apontada no arquivo
		 * SEEK_SET -> informa que deve comecar a ler a partir da posicao 5
		 *
		 * fread(teste, 1, 10, fp)
		 *
		 * teste -> variavel para armazenar o resultado
		 * 1 -> tamanho do tipo para armazenar, como eh char, utiliza 1, se fosse inteiro seria 4
		 * 10 -> tamanho maximo para ler, neste caso vai ler 10 caracteres a partir da posicao 5 do arquivo
		 *
		 */

		for (long int i = 0; i <= tam; i += 10) {
			teste = (char *)malloc(sizeof(char) * (max + 1)); // precisa fazer a alocacao a cada interacao
			fseek(fp, i, SEEK_SET); // seta a posicao informada
			fread(teste, 1, max, fp); // busca no arquivo o intervalo informado
			cout << teste << endl << "#####" << endl;
		}
	}

	fclose(fp);
}

/**
 * @brief cria um arquivo e guarda informacoes
 *
 * utilizada em C
 */
void Arquivo::createFile() {
	char *str = (char *)malloc(100);
	strcpy(str, "src/files/newFile2.txt");

	FILE *file = fopen(str, "w");

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		char *var = (char *)malloc(50);
		strcpy(var, "texto da variavel\n");

		fprintf(file, "%s", "texto da linha 1\n");
		fprintf(file, "%s", var);
		fprintf(file, "%s", "texto da linha 3\n");

		free(var);
	}
	fclose(file);
	free(str);
}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 *
 * utilizada em C++
 */
void Arquivo::readFile(string path) {
	path.insert(0, "src/files/");

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
 *
 * utilizada em C++
 */
void Arquivo::createFile(string path) {
	path.insert(0, "src/files/");

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

#endif