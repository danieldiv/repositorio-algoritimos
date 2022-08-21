#include "arquivo.hpp"

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
	sprintf(str, "files/%s.txt", path);

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

/**
 * @brief cria um arquivo e guarda informacoes
 *
 * utilizada em C
 */
void Arquivo::createFile() {
	char *str = (char *)malloc(100);
	strcpy(str, "files/newFile2.txt");

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
 *
 * utilizada em C++
 */
void Arquivo::createFile(string path) {
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