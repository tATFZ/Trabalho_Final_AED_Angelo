/*
 * List.c
 */

#include "Lista.h"

/*------------------------------------------*/
/* Funcoes privadas */

static lista posLista(lista l, int idx){
	for (int i = 0; i < idx && l != NULL; i++, l = l->seg);
	if (l == NULL)
		erroFatal("Ultrapassou o final duma lista");
	return l;
}

/*------------------------------------------*/
/* Funcoes publicas */

lista criaNo(obj elem, lista seg){
	lista n = malloc(sizeof(struct no));
	if (n == NULL) semMemoria();
	n->elem = elem;
	n->seg = seg;
	return n;
}

void destroiNo(lista l){
	free(l); // apenas o no' apontado
}

void destroiLista(lista l){
	lista seg;
	for ( ; l != NULL; l = seg){
		seg = l->seg;
		destroiNo(l);
	}
}

void destroiTudoLista(lista l){
	lista seg;
	for ( ; l != NULL; l = seg){
		seg = l->seg;
		destroiTudo(l->elem);
		destroiNo(l);
	}
}

string textoLista(lista l){
	string str = criaStringN(10000);
	strcat(str, "<") ;
	for ( ; l != NULL ; l = l->seg){
		strcat(str, texto(l->elem));
		if (l->seg != NULL)
			strcat(str, " ");
	}
	strcat(str, ">");
	return recriaString(str);
}

bool vaziaLista(lista l){
	return l == NULL;
}

int tamanhoLista(lista l){
	int n = 0;
	for ( ; l != NULL ; l = l->seg, n++);
	return n;
}

obj elementoLista(lista l, int i){
	l = posLista(l, i);
	return l->elem;
}

obj atribuiLista(lista l, obj elem, int i){
	l = posLista(l, i);
	lista res = l->elem;
	l->elem = elem;
	return res;
}

lista insereLista(lista l, obj elem, int i){
	if (i == 0)
		return criaNo(elem, l);
	lista x = posLista(l, i-1); // para antes
	x->seg = criaNo(elem, x->seg);
	return l;
}

lista acrescentaLista(lista l, obj elem){
	if (vaziaLista(l))
		return criaNo(elem, NULL);
	lista x = l;
	for ( ; x->seg != NULL ; x = x->seg);
	x->seg = criaNo(elem, NULL);
	return l;
}

/* Precondicao: 0 <= i < tamanhoLista(l) */
lista removeLista(lista l, int i, obj *elem){
	if (i == 0){
		lista res = l->seg;
		if (elem != NULL)
			*elem = l->elem;
		destroiNo(l);
		return res;
	}
	lista x = posLista(l, i-1); // para antes
	lista apagar = x->seg;
	if (elem != NULL)
		*elem = apagar->elem;
	x->seg = apagar->seg;
	destroiNo(apagar);
	return l;
}

vetor vetorLista(lista l, int *n){
	*n = tamanhoLista(l);
	vetor v = malloc(sizeof(obj) * *n);
	if (v == NULL) semMemoria();
	for (int i = 0 ; l != NULL; i++, l = l->seg){
		v[i] = l->elem;
	}
	return v;
}

// Exercicios

#include "Int.h"

static lista criaIntervalo(int a, int b){
	if (a > b)	// intervalo vazio
		return NULL;
	lista l = criaNo(criaInt(a), NULL), ult = l;	// cria 1. no' fora do ciclo, com ult a apontar para o 1. no'
	for (int i = a + 1 ; i <= b ; i++){
		lista novo = criaNo(criaInt(i), NULL);	// novo no', com o valor correto
		ult->seg = novo;	// acrescenta no final (a seguir a ult)
		ult = novo;		// o novo no' passa a ser o ultimo
	}
	return l;
}

#if IGNORE
static lista criaIntervalo_cresce_ah_cabeca(int a, int b){
	lista res = NULL;
	for (int i = b ; i >= a ; i--)
		res = criaNo(criaInt(i), res);
	return res;
}
#endif

static lista eliminaValoresPares(lista l){
	lista ant = NULL;	// ira' apontar para o no' anterior
	for (lista x = l ; x != NULL ; ){
		if (valorInt(x->elem) % 2 == 0){	// valor par (multiplo de 2)
			lista apaga = x;
			if (ant == NULL){	// apaga na cabeca --> l avanca, x avanca, ant continua a NULL
				l = x->seg;
				x = x->seg;
			}
			else{	// apaga no meio --> x avanca, ant nao avanca
				ant->seg = x->seg;
				x = x->seg;
			}
			destroiNo(apaga);
		}
		else {	// nao apaga --> x avanca, ant avanca
			ant = x;
			x = x->seg;
		}
	}
	return l;
}

void testeLista(void){
	printf("Testando Lista:\n");
	lista l = criaIntervalo(1, 20);
	l = insereLista(l, criaInt(90), 0);
	l = insereLista(l, criaInt(91), 1);
	l = insereLista(l, criaInt(92), 2);
	l = insereLista(l, criaInt(92), 2);
	l = insereLista(l, criaInt(93), 10);
	l = insereLista(l, criaInt(94), 21);
	printf("%s\n", textoLista(l));
	l = acrescentaLista(l, criaInt(98));
	l = acrescentaLista(l, criaInt(99));
	printf("%s\n", textoLista(l));
	l = removeLista(l, 0, NULL);
	l = removeLista(l, 10, NULL);
	printf("%s\n", textoLista(l));
	l = insereLista(l, criaInt(90), 0);
	l = eliminaValoresPares(l);
	printf("%s\n", textoLista(l));
	destroiTudoLista(l);
	printf("acabou\n");
}
