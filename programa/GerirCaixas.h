/*
 * GerirCaixas.h
 */

#ifndef GerirCaixas_h
#define GerirCaixas_h

#include "Util.h"
#include "Dicionario.h"
#include "Str.h"
#include "Int.h"
#include "Info.h"
#include "Sequencia.h"

#include "Caixa.h"

/*------------------------------------------*/
/* Tipo publico */

 typedef struct gerirCaixas *GerirCaixas;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
 criaGerirCaixas - Cria o GerirCaixas.
 Parametros: nada
 Retorno: O GerirCaixas
 Precondicao: O GerirCaixas ainda nao existe
***********************************************/
GerirCaixas criaGerirCaixas(void);

/***********************************************
destroi_GerirCaixas - Destroi o GerirCaixas
Parametros: g - GerirCaixas
Retorno: nada
Precondicao: O GerirCaixas existe
***********************************************/
void destroi_GerirCaixas(GerirCaixas g);

/***********************************************
destroiTudo_GerirCaixas - Destroi o GerirCaixas e os seus elementos
Parametros: g - GerirCaixas
Retorno: nada
Precondicao: O GerirCaixas existe
***********************************************/
void destroiTudo_GerirCaixas(GerirCaixas g);

/***********************************************
 existeClienteGerirCaixas - Verifica se existe o cliente d na caixa c.
 Parametros: c - caixa, d - cliente
 Retorno: True se existe, False caso contrario
 Precondicao: O GerirCaixas existe e o cliente tambem
***********************************************/
bool existeClienteGerirCaixas(GerirCaixas g, Cliente d);

/***********************************************
 devolveNumeroGerirCaixas - Devolve o numero de caixas
 Parametros: g - GerirCaixas
 Retorno: Numero de caixas, ou "-1" - se o GerirCaixas nao existir
 Precondicao: O GerirCaixas existe
***********************************************/
int devolveNumeroGerirCaixas(GerirCaixas g);

/***********************************************
 adicionaClienteGerirCaixas - Adiciona o cliente na caixa desejada.
 Parametros: g - GerirCaixas, d - cliente, caixa - numero da caixa
 Retorno: nada
 Precondicao: O GerirCaixas existe e o cliente tambem
***********************************************/
void adicionaClienteGerirCaixas(GerirCaixas g, Cliente d, int caixa);

/***********************************************
 melhorTempoGerirCaixas - Devolve o id da caixa mais rapida
 Parametros: g - GerirCaixas, cestovazio - numero que indica se o cesto esta vazio
 Retorno: Numero do id da caixa mais rapida, ou  "-1" - se o GerirCaixas nao existir
 Precondicao: O GerirCaixas existe
***********************************************/
int melhorTempoGerirCaixas(GerirCaixas g, int cestovazio);

/***********************************************
 devolveCaixaGerirCaixas - Devolve a caixa com o id indicado
 Parametros: g - GerirCaixas, idCaixa - o id da caixa
 Retorno: Caixa pretendida, ou NULL se o GerirCaixas nao existir ou o id da caixa for incorreto
 Precondicao: O GerirCaixas existe e a caixa tambem
***********************************************/
Caixa devolveCaixaGerirCaixas(GerirCaixas g, int idCaixa);

/***********************************************
 removeClienteGerirCaixas - Remove o cliente na fila da caixa escolhida
 Parametros: g - GerirCaixas, idCaixa - o id da caixa
 Retorno: nada
 Precondicao: O GerirCaixas existe e a caixa tambem
***********************************************/
void removeClienteGerirCaixas(GerirCaixas g, int idCaixa);

#endif /*GerirCaixas_h*/

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/