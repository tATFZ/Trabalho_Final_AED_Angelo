/*
 * IteradorVetor.c
 */

#include "Iterador.h"

/*------------------------------------------*/
/* Tipo privado */

struct Iterador{
	Info info;
	vetor copia;
	int numElems;
	int corrente;
};

/*------------------------------------------*/
/* Funcoes publicas */

Iterador criaIterador(vetor copia, int n){
	Iterador it = malloc(sizeof(struct Iterador));
	if (it == NULL) semMemoria();
	it->info = criaInfo("Iterador", destroiIterador, NULL,
					NULL, NULL, textoIterador);
	it->copia = copia;
	it->numElems = n;
	it->corrente = 0;
	return it;
}

Iterador criaIteradorOrdenado(vetor copia, int n){
	ordenaVetor(copia, n);
	return criaIterador(copia, n);
}

void destroiIterador(Iterador it){
	free(it->copia);	// destroi a copia
	free(it);
}

string textoIterador(Iterador it){
	return textoVetor(it->copia, it->numElems);
}

bool temSeguinteIterador(Iterador it){
	return it->corrente < it->numElems;
}

/* Precondicao: it != NULL && temSeguinteIterador(it) */
obj seguinteIterador(Iterador it){
	return it->copia[it->corrente++];
}

#include "Int.h"

void testeIterador(void){
	printf("Testando Iterador:\n\t");
	int cap = 17;
	vetor v = malloc(sizeof(obj) * cap);
	if (v == NULL) semMemoria();
	for (int valor = 0; valor < cap; valor++)
		v[valor] = criaInt(valor);
	Iterador it = criaIterador(v, cap);
	printf("%s\n", textoIterador(it));
	destroiIterador(it);
}
