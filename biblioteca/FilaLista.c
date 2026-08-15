/*
 * FilaLista.c
 */

#include "Fila.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Fila{
	Info info;
	lista elems;
	lista ultimo;
};

/*	Os elementos entram pelo final da lista e saem pela
	cabeca da lista.
	Entrar pelo final da lista sera' ineficiente
	`a partida, por obrigar a percorrer toda a lista
	sempre que se acrescenta um novo elemento.
	Por isso, foi adicionado um apontador direto para
	o ultimo no' da lista. Assim ja' ficou eficiente.
*/

/*------------------------------------------*/
/* Funcoes publicas */

Fila criaFila(void){
	Fila f = malloc(sizeof(struct Fila));
	if (f == NULL) semMemoria();
	f->info = criaInfo("Fila", destroiFila, destroiTudoFila,
				NULL, NULL, textoFila);
	f->elems = NULL;	// lista vazia
	f->ultimo = NULL;	// inicialmente, nao ha ultimo
	return f;
}

void destroiFila(Fila f){
	destroiLista(f->elems);
	free(f);
}

void destroiTudoFila(Fila f){
	destroiTudoLista(f->elems);
	free(f);
}

string textoFila(Fila f){
	return textoLista(f->elems);
}

bool vaziaFila(Fila f){
	return vaziaLista(f->elems);
}

int tamanhoFila(Fila f){
	return tamanhoLista(f->elems);
}

/* Precondicao: f != NULL && !vaziaFila(f) */
obj primeiroFila(Fila f){
	return elementoLista(f->elems, 0);
}

void acrescentaFila(Fila f, obj elem){
	f->ultimo = acrescentaLista(f->ultimo, elem);
	if (vaziaFila(f))
		f->elems = f->ultimo;
}

/* Precondicao: f != NULL && !vaziaFila(f) */
obj removeFila(Fila f){
	obj res;
	f->elems = removeLista(f->elems, 0, &res);
	if (vaziaFila(f))
		f->ultimo = NULL;
	return res;
}

Iterador iteradorFila(Fila f){
	int n;
	vetor v = vetorLista(f->elems, &n);
	return criaIterador(v, n);
}

Iterador iteradorOrdenadoFila(Fila f){
	int n;
	vetor v = vetorLista(f->elems, &n);
	return criaIteradorOrdenado(v, n);
}

#include "Int.h"

void testeFila(void){
	printf("Testando Fila:\n");
	Fila f = criaFila();
	acrescentaFila(f, criaInt(0));
	acrescentaFila(f, criaInt(1));
	acrescentaFila(f, criaInt(2));
	acrescentaFila(f, criaInt(3));
	printf("%s\n", textoFila(f));

	Iterador it = iteradorFila(f);
	while (temSeguinteIterador(it))
		printf("%s\n", texto(seguinteIterador(it)));
	destroiIterador(it);

	printf("primeiro = %s\n", texto(primeiroFila(f)));
	printf("remove = %s\n", texto(removeFila(f)));
	printf("%s\n", texto(f));
	printf("remove = %s\n", texto(removeFila(f)));
	printf("%s\n", texto(f));
	printf("remove = %s\n", texto(removeFila(f)));
	printf("%s\n", texto(f));
	printf("remove = %s\n", texto(removeFila(f)));
	printf("%s\n", texto(f));
	acrescentaFila(f, criaInt(9));
	printf("%s\n", textoFila(f));
}
