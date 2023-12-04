#include "Aleatorio.h"

Aleatorio::Aleatorio (MatrizCosto matriz, int largo) {
	this->matriz = matriz;
	// Los candidatos
	for (int i = 0 ; i < largo ; i++) {
		candidatos.push_back(i);
	}

	// Elección aleatoria
	while (candidatos.size() > 1) {}
}
