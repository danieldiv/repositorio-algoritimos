#include "./include/util.hpp"

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
	for (auto itr = mapeamento.begin(); itr != mapeamento.end(); ++itr) {
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

/**
 * @brief Modifica a cor da linha no terminal
 *
 */
void Util::mudarCorTerminal() {
	printf(VERMELHO "Texto em vermelho" RESET "\n");
	printf(VERDE "Texto em verde" RESET "\n");
	printf(AZUL "Texto em azul" RESET "\n");
}

void Util::combinacoes(int *vec, int perm[], int index, int n, int k) {
	static int count = 0;

	if (count == k) {
		for (int i = 0; i < n; i++)
			if (perm[i] == 1)
				printf("%d ", vec[i]);
		printf("\n");

	} else if ((n - index) >= (k - count)) {

		perm[index] = 1;
		count++;
		combinacoes(vec, perm, index + 1, n, k);

		perm[index] = 0;
		count--;
		combinacoes(vec, perm, index + 1, n, k);

	}
}

void Util::combinacoes(vector<int> *vec, int perm[], int index, int n, int k) {
	static int count = 0;

	if (count == k) {
		for (int i = 0; i < n; i++)
			if (perm[i] == 1)
				cout << vec->at(i) << " ";
		cout << endl;

	} else if ((n - index) >= (k - count)) {

		perm[index] = 1;
		count++;
		combinacoes(vec, perm, index + 1, n, k);

		perm[index] = 0;
		count--;
		combinacoes(vec, perm, index + 1, n, k);

	}
}

void Util::stringMinuscula() {
	string str = "Possui caractereS MAiuscUlos";

	cout << str << endl;
	tolowerStr(str);
	cout << str << endl;
}

// matriz tridimensional quadrada
void Util::matrizTridimensional() {
	cout << "TAM: " << TAM << endl;
	cout << "Linha x Coluna: " << N << " : " << N << endl << endl;

	int ***m = (int ***)malloc(sizeof(int **) * TAM);

	for (int i = 0; i < TAM; i++) {
		m[i] = (int **)malloc(sizeof(int *) * N);

		for (int j = 0; j < N; j++) {
			m[i][j] = (int *)malloc(sizeof(int) * N);
		}
	}

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				m[i][j][k] = i + j + k;
		}
	}

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cout << m[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}