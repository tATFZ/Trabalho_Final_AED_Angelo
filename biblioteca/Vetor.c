/*
 * Vetor.c
 */

#include "Vetor.h"

/*------------------------------------------*/
/* Funcoes privadas */

static void troca(obj *ob1, obj *ob2){
	obj aux = *ob1;
	*ob1 = *ob2;
	*ob2 = aux;
}

/*------------------------------------------*/
/* Funcoes publicas */

vetor copiaVetor(vetor v, int n){
	vetor original = v;
	vetor copia = malloc(sizeof(obj) * n);
	for (int i = 0 ; i < n ; i++){
		copia[i] = original[i];
	}
	return copia;
}

void ordenaVetor(vetor v, int n){
	for (int i=0; i < n-1; i++){
		int minIdx = i;	// procura o minimo seguinte
		for (int j=i+1; j < n; j++){
			if (compara(v[j], v[minIdx]) < 0)
				minIdx = j;
		}
		troca(&v[i], &v[minIdx]);
	}
}

bool homogeneoVetor(vetor v, int n){
	for (int i = 1 ; i < n ; i++){
		if (!mesmoTipo(v[0], v[i]))
			return false;
	}
	return true;
}

string textoVetor(vetor v, int n){
	string str = criaStringN(10000);
	strcat(str, "[") ;
	for (int i = 0; i < n; i++){
		strcat(str, texto(v[i]));
		if (i < n-1)
			strcat(str, " ");
	}
	strcat(str, "]");
	return recriaString(str);
}
