#include <iostream>
#include "binario.h"
#include "genetico.h"

using namespace std;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define DEFAULT "\033[m"

bool avaliacao(unsigned short solucao) {
	int pesoTotal = 0, valorTotal = 0, pesoLimite = 20;

	// verifica o peso e preço total dos objetos selecionados
	if (testarBit(solucao, 15)) {
		pesoTotal += 12;
		valorTotal += 4;
	}
	if (testarBit(solucao, 14)) {
		pesoTotal += 3;
		valorTotal += 4;
	}
	if (testarBit(solucao, 13)) {
		pesoTotal += 5;
		valorTotal += 8;
	}
	if (testarBit(solucao, 12)) {
		pesoTotal += 4;
		valorTotal += 10;
	}
	if (testarBit(solucao, 11)) {
		pesoTotal += 9;
		valorTotal += 15;
	}
	if (testarBit(solucao, 10)) {
		pesoTotal += 1;
		valorTotal += 3;
	}
	if (testarBit(solucao, 9)) {
		pesoTotal += 2;
		valorTotal += 1;
	}
	if (testarBit(solucao, 8)) {
		pesoTotal += 3;
		valorTotal += 1;
	}
	if (testarBit(solucao, 7)) {
		pesoTotal += 4;
		valorTotal += 2;
	}
	if (testarBit(solucao, 6)) {
		pesoTotal += 1;
		valorTotal += 10;
	}
	if (testarBit(solucao, 5)) {
		pesoTotal += 2;
		valorTotal += 20;
	}
	if (testarBit(solucao, 4)) {
		pesoTotal += 4;
		valorTotal += 15;
	}
	if (testarBit(solucao, 3)) {
		pesoTotal += 5;
		valorTotal += 10;
	}
	if (testarBit(solucao, 2)) {
		pesoTotal += 2;
		valorTotal += 3;
	}
	if (testarBit(solucao, 1)) {
		pesoTotal += 4;
		valorTotal += 4;
	}
	if (testarBit(solucao, 0)) {
		pesoTotal += 1;
		valorTotal += 12;
	}
	
	// formatação do texto exibido na tela
	cout << right; cout.width(5); 
	cout << solucao << " - $" << valorTotal << " - ";
	cout.width(2);
	cout << pesoTotal << "Kg - ";

	// adiciona cor ao simbolo de X e OK
	if (pesoTotal > pesoLimite)
		cout << RED << "X" << DEFAULT << '\n';
	else
		cout << GREEN << "OK" << DEFAULT << '\n';

	if (pesoTotal > pesoLimite)
		return false;
}

unsigned short cruzamentoPontoUnico(unsigned short solucao1, unsigned short solucao2) {
	return binarioOu(bitsAltos(solucao1), bitsBaixos(solucao2));
}

unsigned short cruzamentoAritmetico(unsigned short solucao1, unsigned short solucao2) {
	return binarioE(solucao1, solucao2);
}

unsigned short mutacaoSimples(unsigned short solucao) {
	if (testarBit(solucao, 9))
		return desligarBit(solucao, 9);
	else
		return ligarBit(solucao, 9);
}

unsigned short mutacaoDupla(unsigned short solucao) {
	if (testarBit(solucao, 12))
		solucao = desligarBit(solucao, 12);
	else
	solucao = ligarBit(solucao, 12);

	if (testarBit(solucao, 3))
		solucao = desligarBit(solucao, 3);
	else
		solucao = ligarBit(solucao, 3);

	return solucao;
}