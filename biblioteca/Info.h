/*
 * Info.h
 */

#ifndef INFO_H
#define INFO_H

#include "Util.h"

/***********************************************
	TAD Info - Blocos informativos para objetos

Este TAD oferece algumas definicoes que
suportam a definicao de tipos de objetos
usaveis em colocoes genericas.

Uma colecao generica guarda objetos de tipo
indeterminado, e precisa de conseguir
aplicar aos seus objetos algumas das seis
operacoes seguintes:
	tipo,
	destroi,
	destroiTudo,
	compara,
	dispersao,
	texto.
***********************************************/

/*------------------------------------------*/
/* Tipos publicos */

typedef struct Info *Info;
typedef void *obj;	// tipo generico dos objetos

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaInfo - Cria um bloco de informacao para um objeto.
Parametros:
	tipo - tipo pretendido para o objeto (e' uma string)
	destroi - funcao de destruicao
	destroiTudo - funcao de destruicao completa (para colecoes)
	compara - funcao de comparacao
	dispersao - funcao de dispersao
	texto - gerador de representacao textual para debug
Retorno: o bloco de informacao criado
Precondicao: tipo != NULL && destroi != NULL
	(os restantes argumentos podem ser NULL, para indicar ausencia)
***********************************************/
Info criaInfo(string tipo, void *destroi, void *destroiTudo,
		void *compara, void *dispersao, void *texto);

/***********************************************
mesmoTipo - Testa se dois objetos sao do mesmo tipo.
Parametros: ob1, ob2 - objetos para comparar o seu tipo
Retorno: true - se mesmo tipo; false - caso contrario
Precondicao: ob1 != NULL && ob2 != NULL
***********************************************/
bool mesmoTipo(obj ob1, obj ob2);

/***********************************************
tipo - Obtem o tipo dum objeto.
Parametros: ob - objeto
Retorno: o tipo e' uma string
Precondicao: ob != NULL
***********************************************/
string tipo(obj ob);

/***********************************************
destroi - Destroi um objeto generico.
Parametros: ob - objeto generico
Retorno: nada
Precondicao: ob != NULL
***********************************************/
void destroi(obj ob);

/***********************************************
destroiTudo - Destroi um objeto generico completamente,
	que sera' provavelmente uma colecao.
Parametros: ob - objeto generico
Retorno: nada
Precondicao: ob != NULL
***********************************************/
void destroiTudo(obj ob);

/***********************************************
compara - Compara dois objetos genericos.
Parametros: ob1, ob2 - objetos genericos
Retorno: 0 se i1 = i2; -1 se i1 < i2; 1 se i1 > i2
Precondicao: ob1 != NULL && ob2 != NULL
***********************************************/
int compara(obj ob1, obj ob2);

/***********************************************
dispersao - Funcao de dispersao.
Parametros:
	ob - objeto generico
	dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: ob != NULL && dim > 0
***********************************************/
int dispersao(obj ob, int dim);

/***********************************************
texto - Converte em texto, para mostrar em situacoes de debug.
Parametros: ob - objeto generico
Retorno: o texto criado
Precondicao: ob != NULL
***********************************************/
string texto(obj ob);

#endif /* INFO_H */
