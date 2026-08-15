/*
 * Supermercado.h
 */

#ifndef Supermercado_h
#define Supermercado_h

#include"Sequencia.h"
#include"Iterador.h"
#include"Info.h"
#include"Str.h"
#include"Int.h"
#include"Dicionario.h"

#include"Produto.h"
#include"Stock.h"
#include"Cliente.h"
#include"GerirClientes.h"
#include"GerirCaixas.h"
#include"Historia.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct supermercado *Supermercado;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
invalidos - Dados invalidos.
Parametros: Nao tem parametros de entrada
Retorno: Printf "Dados invalidos"
Precondicao: Nenhuma
***********************************************/
void invalidos(void);

/***********************************************
naoPode - Nao pode fazer isso.
Parametros: Nao tem parametros de entrada
Retorno: Printf "Nao pode fazer isso"
Precondicao: Nenhuma
***********************************************/
void naoPode(void);

/***********************************************
escreveproduto - Printf os dados do produto.
Parametros: p - produto
Retorno: Printf os dados do produto
Precondicao: Nenhuma
***********************************************/
void escreveproduto(Produto p);

/***********************************************
escrevecaixa - Printf os dados da caixa.
Parametros: c - caixa
Retorno: Printf os dados da caixa
Precondicao: Nenhuma
***********************************************/
void escrevecaixa(Caixa c);

/***********************************************
criaSupermercado - Cria o supermercado.
Parametros: Nao tem parametros de entrada
Retorno: O supermercado criado
Precondicao: O supermercado nao existe
***********************************************/
Supermercado criaSupermercado(void);

/***********************************************
destroiTudoSupermercado - Destroi o supermercado.
Parametros: m - supermercado
Retorno: Nao tem retorno
Precondicao: m != NULL
***********************************************/
void destroiTudoSupermercado(Supermercado m);

/***********************************************
existeProdutoStockAux - Verifica se existe o produto no stock.
Parametros: m - supermercado, nome - nome do produto
Retorno: true se existe o produto no stock, false caso nao exista
Precondicao: m != NULL e nome != NULL
***********************************************/
bool existeProdutoStockAux(Supermercado m, string nome);

/***********************************************
criaProdutoStockAux - Adiciona um produto ao stock.
Parametros: m - supermercado, nome - nome do produto, quantidade - quantidade do produto, preco - preco do produto, peso - peso do produto
Retorno: nada
Precondicao: m != NULL 
***********************************************/
void criaProdutoStockAux(Supermercado m, string nome, int quantidade, int preco, int peso);

/***********************************************
cmdCriaProdutoStock - Adiciona um produto ao stock.
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL e args != NULL
***********************************************/
void cmdCriaProdutoStock(Supermercado m, string args);

/***********************************************
acrescentaUnidadesProdutoStockAux - Acrescenta x unidades de um produto ao stock.
Parametros: m - supermercado, nome - nome do produto, quantidade - quantidade a adicionar
Retorno: nada
Precondicao: m != NULL 
***********************************************/
void acrescentaUnidadesProdutoStockAux(Supermercado m, string nome, int quantidade);

/***********************************************
temStockAux - Verifica se temos stock.
Parametros: m - supermercado
Retorno: true se existe stock, false caso nao exista
Precondicao: m != NULL
***********************************************/
bool temStockAux(Supermercado m);

/***********************************************
devolveProdutoStockAux - Devolve o produto do stock.
Parametros: m - supermercado, chave - chave/nome do produto
Retorno: Produto do stock
Precondicao: m != NULL
***********************************************/
Produto devolveProdutoStockAux(Supermercado m, string chave); 

/***********************************************
listaStockAux - Devolve o iterador das chaves do stock
Parametros: m - supermercado
Retorno: Iterador ordenado das chaves do stock
Precondicao: m != NULL
***********************************************/
Iterador listaStockAux(Supermercado m);

/***********************************************
cmdAcrescentaUnidadesProdutoStock - Adiciona x unidades de um produto ao stock.
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: s != NULL e args != NULL
***********************************************/
void cmdAcrescentaUnidadesProdutoStock(Supermercado m, string args);

/***********************************************
cmdListaStock - Lista o stock por ordem alfabetica.
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL e args != NULL
***********************************************/
void cmdListaStock(Supermercado m, string args);

/***********************************************
numeroAtualClienteAux - Funcao auxiliar para devolver o numero atual do cliente
Parametros: m - supermercado
Retorno: numero atual do cliente, "-1" - se o supermercado nao existir
Precondicao: m != NULL
***********************************************/
int numeroAtualClienteAux(Supermercado m);

/***********************************************
adicionaClienteSupermercadoAux - Funcao auxiliar para adicionar o cliente ao dicionario de clientes
Parametros: m - supermercado, numCliente - Numero Cliente
Retorno: nada
Precondicao: m != NULL
***********************************************/
void adicionaClienteSupermercadoAux(Supermercado m);

/***********************************************
cmdCliente - Funcao para adicionar um cliente ao Supermercado 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdCliente(Supermercado m, string args);

/***********************************************
acrescentaUnidadesProdutoCestoCliente - Funcao para adicionar x unidades de um produto ao cesto do cliente
Parametros: m - supermercado, p - nome do produto, n - quantidade, numCliente - numero do cliente
Retorno: nada
Precondicao: m != NULL
***********************************************/
void acrescentaUnidadesProdutoCestoCliente(Supermercado m , string p, int n, int numCliente);

/***********************************************
cmdAdicionaProdutoCestoCliente - Funcao para adicionar x unidades de um produto ao cesto do cliente 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdAdicionaProdutoCestoCliente(Supermercado m, string args);

/***********************************************
cmdListaClientes - Funcao que lista os clientes presentes no supermercado 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdListaClientes(Supermercado m, string args);

/***********************************************
temCaixas - Verifica se existem caixas no supermercado
Parametros: m - supermercado
Retorno: true se existir pelo menos uma caixa, false caso contrario
Precondicao: nenhuma
***********************************************/
bool temCaixas(Supermercado m);

/***********************************************
devolveClienteGCAux - Devolve o cliente correspondente a um número, a partir do supermercado
Parametros: m - supermercado, cliente - número do cliente
Retorno: Cliente correspondente ou NULL se não existir
Precondicao: m != NULL, cliente válido
***********************************************/
Cliente devolveClienteGCAux(Supermercado m, int cliente);

/***********************************************
devolveIteradorOrdenadoChaveGCAux - Devolve um iterador com os números dos clientes por ordem crescente
Parametros: m - supermercado
Retorno: Iterador ordenado com os números dos clientes
Precondicao: m != NULL
***********************************************/
Iterador devolveIteradorOrdenadoChaveGCAux(Supermercado m);

/***********************************************
 adicionaProdutoCestoClienteAux - Adiciona o produto no cesto do cliente
 Parametros: m - supermercado,  numCliente - numero do cliente, nome - nome do produto, quantidade - quantidade do produto
 Retorno: nada
 Precondicao: m != NULL
***********************************************/
void adicionaProdutoCestoClienteAux(Supermercado m, string nome, int numCliente, int quantidade);

/***********************************************
 devolveGerirClientesSupermercado - devolve o GerirClientes
 Parametros: m - supermercado
 Retorno: Gerir Clientes
 Precondicao: m != NULL
***********************************************/
GerirClientes devolveGerirClientesSupermercado(Supermercado m);

/***********************************************
 devolveGerirCaixasSupermercado - devolve o GerirCaixas
 Parametros: m - supermercado
 Retorno: Gerir Caixas
 Precondicao: m != NULL
***********************************************/
GerirCaixas devolveGerirCaixasSupermercado(Supermercado m);

/***********************************************
cestoVazioClienteGCAux - Verifica se o cesto esta vazio
Parametros: m - supermercado, numCliente - numero do cliente
Retorno: True se esta vazio, false caso contrario
Precondicao: o Supermercado existe
***********************************************/
bool cestoVazioClienteGCAux(Supermercado m, int numCliente);

/***********************************************
existeClienteGerirCaixasAux - Verifica se o cliente esta em alguma caixa
Parametros: m - supermercado, numCliente - numero do cliente
Retorno: True se ja esta numa caixa , false caso contrario
Precondicao: o Supermercado existe
***********************************************/
bool existeClienteGerirCaixasAux(Supermercado m, int numCliente);

/***********************************************
adicionaClienteCaixaAux - Adiciona o cliente na caixa desejada
Parametros: m - supermercado, numCaixa - numero da caixa, numCliente - numero do cliente
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void adicionaClienteCaixaAux(Supermercado m, int numCaixa, int numCliente);

/***********************************************
cmdAdicionaClienteCaixa - Funcao que adiciona o cliente na caixa desejada 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdAdicionaClienteCaixa(Supermercado m, string args);

/***********************************************
 devolveNumeroGerirCaixasAux - Devolve o numero de caixas
 Parametros: m - supermercado
 Retorno: numero de caixas, "-1" - se o supermercado nao existir
 Precondicao: o Supermercado existe
***********************************************/
int devolveNumeroGerirCaixasAux(Supermercado m);

/***********************************************
 melhorTempoGerirCaixasAux - Devolve o id da caixa mais rapida
 Parametros: m - supermercado
 Retorno: Numero do id da caixa mais rapida, ou  "-1" - se o supermercado nao existir
 Precondicao: o Supermercado existe
***********************************************/
int melhorTempoGerirCaixasAux(Supermercado m, int numCliente);

/***********************************************
cmdAdicionaClienteMelhorCaixa - Funcao que adiciona o cliente na melhor caixa 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdAdicionaClienteMelhorCaixa(Supermercado m, string args);

/***********************************************
alteraCaixaGCAux - Altera o id da caixa do cliente
Parametros: m - supermercado , numCliente - numero do cliente, caixaCliente - numero da caixa do cliente
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void alteraCaixaGCAux(Supermercado m, int numCliente, int caixaCliente);

/***********************************************
devolveIdCaixaGCAux - Devolve o id da caixa onde o cliente esta
Parametros: m - supermercado, numCliente - numero do cliente
Retorno: id da caixa onde o cliente esta, "-1" - se o GerirClientes nao existir
Precondicao: o Supermercado existe
***********************************************/
int devolveIdCaixaGCAux(Supermercado m, int numCliente);

/***********************************************
devolveCaixaGerirCaixasAux - Devolve a caixa com o id indicado
Parametros: m - supermercado, idCaixa - id da caixa
Retorno: caixa com o id indicado, NULL se algo nao existir
Precondicao: o Supermercado existe, e a caixa de id idCaixa existe
***********************************************/
Caixa devolveCaixaGerirCaixasAux(Supermercado m, int idCaixa);

/***********************************************
devolveDinheiroClienteAux - devolve Dinheiro Cliente
Parametros: c - Cliente
Retorno: valor total do dinheiro do cliente em centimos, ou  "-1" - se o supermercado nao existir
Precondicao: cliente existe
***********************************************/
int devolveDinheiroClienteAux(Cliente c);

/***********************************************
cmdListaCaixas - Funcao que listas as caixas
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdListaCaixas(Supermercado m, string args);

/***********************************************
avancaTempoSupermercado - Avanca x tempo no supermercado
Parametros: m - supermercado, avancaTempo - tempo a avancar
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void avancaTempoSupermercado(Supermercado m, int avancaTempo);

/***********************************************
passaUmSegundoCaixaSupermercado - Avanca um segundo na caixa
Parametros: m - supermercado, idCaixa - id da caixa
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void passaUmSegundoCaixaSupermercado(Supermercado m, int idCaixa);

/***********************************************
devolveTempoSupermercado - Devolve o tempo decorrido no supermercado
Parametros: m - supermercado
Retorno: tempo decorrido no supermercado, ou  "-1" - se o supermercado nao existir
Precondicao: o Supermercado existe
***********************************************/
int devolveTempoSupermercado(Supermercado m);

/***********************************************
cmdAvancaTempo - Funcao que avanca o tempo do supermercado
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdAvancaTempo(Supermercado m, string args);

/***********************************************
adicionaRegistoAux - Cria um registo e adiciona no historico
Parametros: m - supermercado, cliente - id do Cliente, momento - tempo, pagou - quanto pagou, peso - quanto pesa 
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void adicionaRegistoAux(Supermercado m, int cliente, int caixa, int momento, int pagou, int peso);

/***********************************************
listaHistoricoAux - Lista o historico 
Parametros: m - supermercado
Retorno: nada
Precondicao: o Supermercado existe
***********************************************/
void listaHistoricoAux(Supermercado m);

/***********************************************
cmdListaHistorico - Funcao que lista o historico
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdListaHistorico(Supermercado m, string args);

/***********************************************
devolveItHistoricoAux - Devolve o iterador do historico
Parametros: m - supermercado
Retorno: Iterador de registos do historico
Precondicao: m != NULL
***********************************************/
Iterador devolveItHistoricoAux(Supermercado m);

/***********************************************
existeClienteGCAux - Verifica se existem clientes no GerirClientes
Parametros: m - Supermercado
Retorno: True se esta vazio, false caso contrario
Precondicao: o Supermercado existe
***********************************************/
bool existeClienteGCAux(Supermercado m);

/***********************************************
cmdFimImediato - Funcao que da printf do fim 
Parametros: m - supermercado, args - linha que sera analizada
Retorno: nada
Precondicao: m != NULL
***********************************************/
void cmdFimImediato(Supermercado m, string args);

#endif /*Supermercado_h*/


/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/

//gcc -Wall -Ibiblioteca -Iprograma biblioteca/*.c programa/*.c -o prog.exe


