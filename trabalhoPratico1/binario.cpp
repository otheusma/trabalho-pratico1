#include "binario.h";

unsigned short ligarBit(unsigned short valor, int posicao) {
	return binarioOu(valor, mascaraBit(posicao));
}

unsigned short desligarBit(unsigned short valor, int posicao) {
	if (testarBit(valor, posicao))
		return valor ^ mascaraBit(posicao);
	else
		return valor;
}

bool testarBit(unsigned short valor, int posicao) {
	return valor & mascaraBit(posicao);
}

unsigned short binarioE(unsigned short val1, unsigned short val2) {
	return val1 & val2;
}

unsigned short binarioOu(unsigned short val1, unsigned short val2) {
	return val1 | val2;
}

unsigned short bitsBaixos(unsigned short valor) {
	valor <<= 8;
	valor >>= 8;
	return valor;
}

unsigned short bitsAltos(unsigned short valor) {
	valor >>= 8;
	valor <<= 8;
	return valor;
}

unsigned short mascaraBit(int posicao) {
	unsigned short mascara = 1 << posicao;
	return mascara;
}