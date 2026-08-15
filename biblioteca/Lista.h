/*
 * Lista.h
 */

#ifndef LISTA_H
#define LISTA_H

#include "Util.h"
#include "Info.h"
#include "Vetor.h"

/***********************************************
	Modulo Lista - Listas genericas (nao e' TAD)
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct no {
	obj elem;
	struct no *seg;	// tipo recursivo
} *lista;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaNo - Cria um no.
Parametros:
	elem - o elemento guardado
	seg - o no' seguinte guardado
Retorno: o no' criado
Precondicao: elem != NULL (seg pode ser NULL)
***********************************************/
lista criaNo(obj elem, lista seg);

/***********************************************
destroiNo - Elimina o no' apontado por l.
Parametros: l - apontador para o no' a eliminar
	(nao elimina a lista completa)
Retorno: nada
Precondicao: l != NULL
***********************************************/
void destroiNo(lista l);

/***********************************************
destroiLista - Elimina todos os nos da lista,
	mas nao os elementos la' guardados.
Parametros: l - lista
Retorno: nada
Precondicao: nada (l pode ser NULL)
***********************************************/
void destroiLista(lista l);

/***********************************************
destroiTudoLista - Elimina todos os nos da lista,
	mais os elementos la' guardados.
Parametros: l - lista
Retorno: nada
Precondicao: nada (l pode ser NULL)
***********************************************/
void destroiTudoLista(lista l);

/***********************************************
textoLista - Converte em texto, para mostrar em situacoes de debug.
Parametros: l - lista
Retorno: o texto criado
Precondicao: nada
***********************************************/
string textoLista(lista l);

/***********************************************
vaziaLista - Testa se a lista esta vazia.
Parametros: l - lista
Retorno: true - se lista vazia; false - caso contrario
Precondicao: nada
***********************************************/
bool vaziaLista(lista l);

/***********************************************
tamanhoLista - Numero de elementos na lista.
Parametros: l - lista
Retorno: numero de elementos
Precondicao: nada
***********************************************/
int tamanhoLista(lista l);

/***********************************************
elementoLista - O i-esimo elemento da lista.
Parametros:
	l - lista
	i - posicao ocupada na lista; conta a partir de 0
Retorno: elemento na posicao i
Precondicao: 0 <= i < tamanhoLista(l)
***********************************************/
obj elementoLista(lista l, int i);

/***********************************************
atribuiLista - Coloca o elemento na posicao ocupada i,
	trocando o elemento que la' se encontrava.
Parametros:
	l - lista
	elem - elemento a colocar
	i - posicao ocupada da lista; conta a partir de 0
Retorno: retorna o elemento que ocupava a posicao i
Precondicao: elem != NULL && 0 <= i < tamanho(l)
***********************************************/
obj atribuiLista(lista l, obj elem, int i);

/***********************************************
insereLista - Insere um elemento na posicao i.
Parametros:
	l - lista
	elem - elemento
	i - posicao ocupada na lista; conta a partir de 0;
		i tambem pode indicar a primeira posicao apos o final
Retorno: nada
Precondicao: elem != NULL && 0 <= i <= tamanho(l)
***********************************************/
lista insereLista(lista l, obj elem, int i);

/***********************************************
acrescentaLista - Acrescenta um elemento no final.
	Equivalente a insereLista(l, elem, tamanhoLista(l)).
Parametros:
	l - lista
	elem - elemento
Retorno: nada
Precondicao: elem != NULL
***********************************************/
lista acrescentaLista(lista l, obj elem);

/***********************************************
removeLista - Remove o elemento da posicao ocupada i.
Parametros:
	l - lista
	i - posicao ocupada na lista; conta a partir de 0
	elem - saida do elemento removido
Retorno: o elemento removido
Precondicao: 0 <= i < tamanhoLista(l)
***********************************************/
lista removeLista(lista l, int i, obj *elem);

/***********************************************
vetorLista - Converte lista para vetor.
Parametros:
	l - lista
	n - saida do tamanho do vetor
Retorno: vetor
Precondicao: nada
***********************************************/
vetor vetorLista(lista l, int *n);

/***********************************************
testeLista - Alguns testes simples.
***********************************************/
void testeLista(void);

#endif /* LISTA_H */
