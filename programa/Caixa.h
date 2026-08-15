/*
 * Caixa.h
 */

#ifndef Caixa_h
#define Caixa_h

#include "Util.h"
#include "Dicionario.h"
#include "Str.h"
#include "Int.h"
#include "Info.h"
#include "Fila.h"

#include "Cliente.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct caixa *Caixa;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
 criacaixa - Cria a caixa.
 Parametros: nada
 Retorno: A caixa
 Precondicao: A caixa ainda nao existe
***********************************************/
Caixa criaCaixa(void);

/***********************************************
destroiCaixa - Destroi a caixa
Parametros: c - caixa
Retorno: nada
Precondicao: a caixa existe
***********************************************/
void destroiCaixa(Caixa c);

/***********************************************
destroiTudoCaixa - Destroi a caixa e os seus elementos
Parametros: c - caixa
Retorno: nada
Precondicao: a caixa existe
***********************************************/
void destroiTudoCaixa(Caixa c);

/***********************************************
 existeClienteCaixa - Verifica se existe o cliente d na caixa c.
 Parametros: c - caixa, d - cliente
 Retorno: True se existe, False caso contrario
 Precondicao: a caixa existe e o cliente tambem
***********************************************/
bool existeClienteCaixa(Caixa c, Cliente d);

/***********************************************
 adicionaClienteCaixa - Adiciona o cliente na caixa desejada.
 Parametros: c - caixa, d - cliente
 Retorno: nada
 Precondicao: a caixa existe e o cliente tambem
***********************************************/
void adicionaClienteCaixa(Caixa c, Cliente d);

/***********************************************
devolveTempoCaixa - Devolve o tempo total da caixa
Parametros: c - caixa
Retorno: tempo da caixa, "-1" - se o caixa nao existir
Precondicao: a caixa existe
***********************************************/
int devolveTempoCaixa(Caixa c);

/***********************************************
devolveIdCaixa - Devolve o id da caixa
Parametros: c - caixa
Retorno: id da caixa, "-1" - se o caixa nao existir
Precondicao: a caixa existe
***********************************************/
int devolveIdCaixa(Caixa c);

/***********************************************
adicionaIdcaixa - Adiciona o id da caixa
Parametros: c - caixa, idCaixa - id da caixa
Retorno: nada
Precondicao: a caixa existe
***********************************************/
void adicionaIdCaixa(Caixa c, int idCaixa);

/***********************************************
devolveItClienteCaixa - devolve o iterador da fila de clientes na caixa c
Parametros: c - caixa
Retorno: O iterador do cliente na caixa, NULL se algum dos 2 nao existir
Precondicao: a caixa existe ou a fila de clientes nao existe 
***********************************************/
Iterador devolveItClienteCaixa(Caixa c);

/***********************************************
removeClienteFila - Remove cliente da caixa
Parametros: c - caixa
Retorno: nada
Precondicao: a caixa existe
***********************************************/
void removeClienteFila(Caixa c);

#endif /*Caixa_h*/

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/