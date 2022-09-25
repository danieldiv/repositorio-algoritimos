#include "./class/arquivo.hpp"

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
	sprintf(str, "src/resource/%s.txt", path);

	FILE *file = fopen(str, "r");

	char *result, linha[100];

	if (file == NULL) {
		printf(VERMELHO "Nao foi possivel abrir o arquivo\n" RESET);
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
	strcpy(str, "src/resource/newFile2.txt");

	FILE *file = fopen(str, "w");

	if (file == NULL) {
		printf(VERMELHO "Nao foi possivel abrir o arquivo\n" RESET);
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
	path.insert(0, "src/resource/");

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
	path.insert(0, "src/resource/");

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

/**
 * @brief le o arquivo pelo intervalo informado
 *
 * @param intervalo de quanto em quanto ira ler o arquivo
 */
void Arquivo::readFileIntervalo(int intervalo, char *arquivo) {
	char *path = (char *)malloc(sizeof(char) * 100);
	FILE *fp;

	sprintf(path, "src/resource/%s.txt", arquivo);
	fp = fopen(path, "r");

	if (fp != NULL) {
		if (intervalo > 0) {
			long int tam;
			char *texto = (char *)malloc(sizeof(char) * 100);

			fseek(fp, 0, SEEK_END); // aponta para o fim da ultima linha
			tam = ftell(fp); // pega a posicao atual, neste caso a ultima posicao do arquivo

			long int index;

			for (long int i = 0; i <= tam; i += intervalo) {
				texto = (char *)malloc(sizeof(char) * (intervalo + 1));
				fseek(fp, i, SEEK_SET); // seta a posicao informada
				fread(texto, 1, intervalo, fp); // busca no arquivo o intervalo informado

				index = strcspn(texto, "\n"); // encontra a posicao que possui o primeiro \n

				if (index != intervalo && (i + index) < tam) {
					if (index > 1) {
						texto = (char *)malloc(sizeof(char) * (index + 1));
						fseek(fp, i, SEEK_SET);
						fread(texto, 1, index - 1, fp);
						printf("%s\n", texto);
					}
					printf(AZUL "---> [fim da linha]\n" RESET);
					i -= intervalo - index - 1;
				} else
					printf("%s\n", texto);
			}
			printf(VERDE "---> [fim do arquivo]\n" RESET);
			free(texto);
		} else
			printf(VERMELHO "intervalo nao pode ser <= 0\n" RESET);
		fclose(fp);
	} else
		printf(VERMELHO "Nao foi possivel abrir o arquivo 10 in 10\n" RESET);
	free(path);
}