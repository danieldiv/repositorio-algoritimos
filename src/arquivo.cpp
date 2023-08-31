#include "./include/arquivo.hpp"

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
	free(str);
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
 * @param path nome do arquivo a ser aberto
 *
 * utilizada em C++
 */
void Arquivo::readFile(string &path) {
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
 * @brief realiza a leitura de um arquivo tokenizando por espaco e faz a sua impressao
 *
 * @param path nome do arquivo a ser aberto
 *
 * utilizada em C++
 */
void Arquivo::readFileTokenizando(string &path) {
	// path.insert(0, "src/resource/");

	ifstream myfile(path);
	string line;

	if (myfile.is_open()) {
		string buffer;
		while (myfile >> buffer)
			cout << buffer << endl;
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo tokenizado: " << path << endl;
}

/**
 * @brief cria um arquivo e guarda informacoes
 *
 * @param file nome do arquivo a ser criado
 *
 * utilizada em C++
 */
void Arquivo::createFile(string &path) {
	path.insert(0, "src/resource/");

	ofstream myfile(path);
	string line;

	if (myfile.is_open()) {
		myfile << "dado 1" << endl;
		myfile << "dado 2" << endl;
		myfile << 25 << endl;
		myfile << "dado 4" << 5.7 << " " << true << " " << 99 << " teste" << endl;

		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo: " << path << endl;
}

/**
 * @brief le o arquivo pelo intervalo informado
 *
 * @param intervalo de quanto em quanto ira ler o arquivo
 */
void Arquivo::readFileIntervalo(size_t intervalo, char *arquivo) {
	char *path = (char *)malloc(sizeof(char) * 100);
	FILE *fp;

	sprintf(path, "src/resource/%s.txt", arquivo);
	fp = fopen(path, "r");

	if (fp != NULL) {
		if (intervalo > 0) {
			fseek(fp, 0, SEEK_END); // aponta para o fim da ultima linha
			size_t filesize = ftell(fp); // pega a posicao atual, neste caso a ultima posicao do arquivo

			if (filesize == 0) {
				printf(VERMELHO "Erro ao ler arquivo\n" RESET);
				return;
			}
			for (size_t i = 0; i < filesize; i += intervalo) {
				if (intervalo + i > filesize)
					intervalo = filesize - i;
				char *buffer = (char *)malloc(intervalo + 1);
				if (buffer == NULL) {
					printf(VERMELHO "Erro ao alocar memoria\n" RESET);
					return;
				}
				fseek(fp, i, SEEK_SET); // seta a posicao informada
				fread(buffer, 1, intervalo, fp); // busca no arquivo o intervalo informado
				buffer[intervalo] = '\0'; // adicionando o caracter nulo, para indicar o fim da string

				if (strlen(buffer) > 0) {
					size_t index = strcspn(buffer, "\n"); // encontra a posicao que possui o primeiro \n

					if (index != intervalo && (i + index) < filesize) {
						if (index > 1) {
							char *aux = (char *)malloc(sizeof(char) * (index + 1));
							fseek(fp, i, SEEK_SET);
							fread(aux, 1, index - 1, fp);
							if (strlen(buffer) > 0) {
								aux[index - 1] = '\0'; // adicionando o caracter nulo, para indicar o fim da string
								printf("%s\n", aux);
							}
							free(aux);
						}
						printf(AZUL "---> [fim da linha]\n" RESET);
						i -= intervalo - index - 1;
					} else
						printf("%s\n", buffer);
				}
				free(buffer);
			}
			printf(VERDE "---> [fim do arquivo]\n" RESET);
		} else
			printf(VERMELHO "intervalo nao pode ser <= 0\n" RESET);
		fclose(fp);
	} else
		printf(VERMELHO "Nao foi possivel abrir o arquivo 10 in 10\n" RESET);
	free(path);
}