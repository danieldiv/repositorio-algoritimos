#ifndef CLASS_TEMPLATE_HPP
#define CLASS_TEMPLATE_HPP

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T, typename U>
class ClassTemplate {
private:
public:
	ClassTemplate();
	~ClassTemplate();

	void printVector(vector<T> &vec);
	void printMap(map<T, vector<U>> &mapeamento);
};

template <typename T, typename U>
ClassTemplate<T, U>::ClassTemplate() {}

template <typename T, typename U>
ClassTemplate<T, U>::~ClassTemplate() {}

/**
 * @brief imprime um vector do tipo T
 *
 * @tparam T
 * @tparam U
 * @param vec
 */
template <typename T, typename U>
void ClassTemplate<T, U>::printVector(vector<T> &vec) {
	for (T val : vec)
		cout << val << " ";
	cout << endl;
}

/**
 * @brief imprime um map atravez de um template
 * o map possui uma chave com um unico tipo T, ou seja, nao eh tupla
 * o valor eh um vector de tipo U
 *
 * @tparam T
 * @tparam U
 * @param mapeamento
 */
template <typename T, typename U>
void ClassTemplate<T, U>::printMap(map<T, vector<U>> &mapeamento) {
	for (auto itr = mapeamento.begin(); itr != mapeamento.end(); ++itr) {
		cout << itr->first << endl;

		for (U dado : itr->second) {
			cout << dado << " ";
		}
		cout << endl;
	}
	cout << endl;
}
#endif