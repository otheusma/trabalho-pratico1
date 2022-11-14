#include <iostream>
#include "binario.h"
#include "genetico.h"

using namespace std;  

int main() {
	unsigned short solucao1, solucao2, solucao3, solucao4, solucao5, solucao6;
	cout << "Entre com 6 solucoes iniciais (numeros entre 0 e 65535):\n";
	cin >> solucao1 >> solucao2 >> solucao3 >> solucao4 >> solucao5 >> solucao6;

	cout << "Resultado da Avaliacao\n";
	cout << "-----------------------\n";
	avaliacao(solucao1);
	avaliacao(solucao2);
	avaliacao(solucao3);
	avaliacao(solucao4);
	avaliacao(solucao5);
	avaliacao(solucao6);
	cout << "-----------------------\n";
	avaliacao(cruzamentoPontoUnico(solucao1, solucao2));
	avaliacao(cruzamentoAritmetico(solucao3, solucao4));
	avaliacao(mutacaoSimples(solucao5));
	avaliacao(mutacaoDupla(solucao6));
}