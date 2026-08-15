/*
 * Int.c
 */

#include "Int.h"

/*------------------------------------------*/
/* Tipo privado */

struct Int {
	Info info;
	int valor;
};

/*------------------------------------------*/
/* Funcoes publicas */

Int criaInt(int valor){
	Int i = malloc(sizeof(struct Int));
	if (i == NULL) semMemoria();
	i->info = criaInfo("Int", destroiInt, destroiInt,
				comparaInt, dispersaoInt, textoInt);
	i->valor = valor;
	return i;
}

void destroiInt(Int i){
	free(i);
}

int comparaInt(Int i1, Int i2){
	int v1 = valorInt(i1);
	int v2 = valorInt(i2);
	return comparaInteiros(v1, v2);
}

int dispersaoInt(Int i, int dim){
	return valorInt(i) % dim;
}

string textoInt(Int i){
	string txt = criaStringN(100);
	sprintf(txt, "%d", valorInt(i));
	return recriaString(txt);
}

int valorInt(Int i){
	return i->valor;
}

void testeInt(void){
	printf("Testando Int:\n");
	Int x = criaInt(3);
	for (int valor = 0 ; valor < 10 ; valor++){
		Int i = criaInt(valor);
		printf("(%s,%d,%d)\n",
			textoInt(i),
			comparaInt(i, x),
			dispersaoInt(i, 4));
		destroiInt(i);
	}
	printf("Testando Int:\n");
	destroiInt(x);
	printf("\n");
}

