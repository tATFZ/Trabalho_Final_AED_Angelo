/*
* MainSupermercado.c
*/

#include "Str.h"
#include "Supermercado.h"
#define MAX_LINHA 64
#define CAIXA_ESPECIAL 0

void invalidos(void){
	printf("Dados invalidos.\n");
}

void naoPode(void){
	printf("Nao pode fazer isso.\n");
}

void escreveproduto(Produto p){ 
    if (p == NULL) {
        return; 
    }
    printf("  Produto %s: %d unidades, %d centimos, %d gramas\n", devolveNomeProduto(p), devolveQuantidadeProduto(p), devolvePrecoProduto(p), devolvePesoProduto(p));   
}

void escrevecaixa(Caixa c){
    if (c == NULL) {
        return; 
    }
    Iterador it = devolveItClienteCaixa(c);

    while(temSeguinteIterador(it)){
        Cliente cl = seguinteIterador(it);
        int idCliente = devolveIdCliente(cl);

    printf("    Cliente %d: %d segundos, %d centimos\n", idCliente, devolveTempoCliente(cl), devolveDinheiroClienteAux(cl));
    }
    destroiIterador(it);
}

void cmdMenu(Supermercado m, string args){
char lixo[MAX_LINHA];
	if (sscanf(args, "%s", lixo) > 0)
		invalidos();
	else {
		printf("  ? - Ajuda\n");
		printf("  C - Cliente novo\n");
		printf("  D x p n - Cliente coloca produto no cesto\n");
		printf("  E - lista Clientes\n");
		printf("  P p n c g - Produto novo\n");
		printf("  Q p n - reabastecimento de Produto.\n");
		printf("  R - lista Produtos em stock\n");
		printf("  X x n - cliente vai para uma Caixa\n");
		printf("  Y x - cliente vai para a melhor Caixa\n");
		printf("  Z - lista Caixas\n");
		printf("  H - lista Historico\n");
		printf("  T s - avanca Tempo\n");
		printf("  F - Fecha o supermercado e termina o programa\n");
		printf("  . - Termina o programa imediatamente\n");
	}
}

void cmdCriaProdutoStock(Supermercado m, string args){
    char nome[MAX_LINHA], lixo[MAX_LINHA];
    int quantidade;
    int preco, peso;
    if (sscanf(args,"%s %d %d %d %s", nome, &quantidade, &preco, &peso, lixo) != 4 || quantidade < 0 || preco < 0 || peso < 0){ //vai buscar os dados do user
        invalidos();
        
    }
    else if(existeProdutoStockAux(m, nome)){ // Verifica se o produto ja existe no stock
        naoPode();
        
    } else{
        criaProdutoStockAux(m , nome, quantidade, preco, peso); // Adiciona o produto ao stock
        printf("Cria o novo produto %s\n", nome);
    }
}

void cmdAcrescentaUnidadesProdutoStock(Supermercado m, string args){
    char nome[MAX_LINHA];
    int quantidade;
    if (sscanf(args,"%s %d", nome, &quantidade) != 2 || quantidade < 0) {   
        invalidos();
     
    }
    else if (!existeProdutoStockAux(m, nome)){ 
        naoPode();
        
    } else {
        acrescentaUnidadesProdutoStockAux(m, nome, quantidade); // Adiciona x unidades produto ao stock
        printf("Reabastece o produto %s\n", nome); 
    }
}

void cmdListaStock(Supermercado m, string args){
    Iterador it = listaStockAux(m);
    printf("-- Stock --\n");
    if (!temStockAux(m)) { //Se o stock estiver vazio
        printf("  vazio\n");
        return;
    }                                                        
    while(temSeguinteIterador(it)){                
        string chave = valorStr(seguinteIterador(it)); // Obtem a chave do produto
        Produto p = devolveProdutoStockAux(m,  chave);// Obtem o produto do dicionario
        escreveproduto(p); // Escreve o produto
    }
    destroiIterador(it);
}

void cmdCliente(Supermercado m, string args){
    char lixo[MAX_LINHA];
    if(sscanf(args, "%s", lixo) > 0){ 
        invalidos();
        return;
    }   
    adicionaClienteSupermercadoAux(m);
   printf("Chega o cliente %d\n", (numeroAtualClienteAux(m))); 
}

void cmdAdicionaProdutoCestoCliente(Supermercado m, string args){
    char nome[MAX_LINHA], lixo[MAX_LINHA];
    int quantidade;
    int numCliente;
    
    if (sscanf(args,"%d %s %d %s",&numCliente, nome, &quantidade, lixo) != 3 || quantidade < 0 || numCliente <0){ 
        invalidos();
        return;
    }
   
    if(!existeProdutoStockAux(m, nome) || ((numCliente) > numeroAtualClienteAux(m))){ // Verifica se existe o produto no stock e se o numCliente esta certo
        naoPode();
        return;
    } 

    Produto p = devolveProdutoStockAux(m, nome); // Vai buscar o produto no stock

    if(devolveQuantidadeProduto(p) < quantidade){// Verifica se a quantidade no stock e' suficiente
        naoPode();
        return;
    }
    
    adicionaProdutoCestoClienteAux(m, nome, numCliente, quantidade); // Adiciona o produto no cesto cliente
    printf("Acrescenta %s\n", nome);
}

void cmdListaClientes(Supermercado m, string args){
    printf("-- Clientes --\n");

    if (existeClienteGCAux(m)) {
        printf("  vazio\n");
        return;
    }

    Iterador it = devolveIteradorOrdenadoChaveGCAux(m);

    while (temSeguinteIterador(it)) {
        int numCliente = valorInt(seguinteIterador(it));
        Cliente c = devolveClienteGCAux(m, numCliente);
        
        if(existeClienteGerirCaixasAux(m, numCliente)){
            int idcaixa = 0;
            idcaixa = devolveIdCaixaGCAux(m, numCliente);
            printf("  Cliente %d [%d]:\n", numCliente, idcaixa);
        } else {
            printf("  Cliente %d:\n", numCliente);
        }
        
        Iterador it2 = iteradorOrdenadoChaveCestoCliente(c);

        if (!temSeguinteIterador(it2)) {
            printf("    vazio\n");
        } else {
            while (temSeguinteIterador(it2)) {
                string nome_produto = valorStr(seguinteIterador(it2));
                Produto p = devolveProdutoCestoCliente(c, nome_produto);
                printf("  ");
                escreveproduto(p);
            }
        }
        destroiIterador(it2);       
    }
    destroiIterador(it);  
}

void cmdAdicionaClienteCaixa(Supermercado m, string args){ 
    char lixo[MAX_LINHA];
    int numCaixa;
    int numCliente;
    
    if (sscanf(args,"%d %d %s",&numCliente, &numCaixa, lixo) != 2 || numCaixa < 0 || numCliente < 0){ 
        naoPode();
        return;
    }
    
    if(!cestoVazioClienteGCAux(m, numCliente) && numCaixa == CAIXA_ESPECIAL){ //Verifica se o cesto do cliente esta vazio se nao, nao pode usar a caixa 0
        naoPode();
        return;

    }

    if(numCaixa > devolveNumeroGerirCaixasAux(m)){// verifica se a caixa escolhida e' valida
        naoPode();
        return;
    }

    if(existeClienteGerirCaixasAux(m, numCliente) ||  ((numCliente) > numeroAtualClienteAux(m))){ //Verifica se o cliente ja esta numa caixa e se o cliente existe no supermercado
        naoPode();
        return;
    }

    alteraCaixaGCAux(m, numCliente, numCaixa); //coloca no cliente o id da caixa
    adicionaClienteCaixaAux(m, numCaixa,  numCliente); //adiciona o cliente na caixa escolhida
    
    printf("Cliente %d para caixa %d\n", numCliente, numCaixa);
}

void cmdAdicionaClienteMelhorCaixa(Supermercado m, string args){ 
    char lixo[MAX_LINHA];
    int numCliente;
    if (sscanf(args,"%d  %s",&numCliente, lixo) != 1 || numCliente < 0){ //vai buscar os dados do cliente e da caixa
        naoPode();
        return;
    }

    if(existeClienteGerirCaixasAux(m, numCliente) ||  ((numCliente) > numeroAtualClienteAux(m))){ //Verifica se o cliente ja esta numa caixa e se o cliente existe no supermercado
        naoPode();
        return;
    }

    int idMelhorCaixa = melhorTempoGerirCaixasAux(m, numCliente);

    if(!cestoVazioClienteGCAux(m, numCliente) && idMelhorCaixa == CAIXA_ESPECIAL){ //verifica se a melhor caixa e' o zero se sim o cesto tem que estar vazio
        naoPode();
        return;
    }
    alteraCaixaGCAux(m, numCliente, idMelhorCaixa); //coloca no cliente o id da caixa
    adicionaClienteCaixaAux(m, idMelhorCaixa, numCliente);//adicionao o cliente na melhor caixa

    printf("Cliente %d para caixa %d\n", numCliente, idMelhorCaixa);
}

void cmdListaCaixas(Supermercado m, string args){   
    printf("-- Caixas --\n");

    if (!temCaixas(m)) { 
        printf("  vazio\n");
        return;
    }
    
    int num_caixas = devolveNumeroGerirCaixasAux(m);
    int idCaixa = 0;

    while ( idCaixa < num_caixas) {
        Caixa c = devolveCaixaGerirCaixasAux(m, idCaixa);
        
        printf("  Caixa %d:\n", idCaixa);
        

        Iterador it = devolveItClienteCaixa(c);
        
        if (!temSeguinteIterador(it)) {
            printf("    vazio\n");
        } else {
                escrevecaixa(c);
        }
        idCaixa++;
        destroiIterador(it);
    }
}

void cmdAvancaTempo(Supermercado m, string args){
    char lixo[MAX_LINHA];
    int avancaTempo;

    if (sscanf(args,"%d  %s",&avancaTempo, lixo) != 1 || avancaTempo < 0){
        naoPode();
        return;
    }
    avancaTempoSupermercado(m, avancaTempo);
    printf("Tempo corrente: %d segundos\n", devolveTempoSupermercado(m));
}

void cmdListaHistorico(Supermercado m, string args){
    char lixo[MAX_LINHA];
    if (sscanf(args, "%s", lixo) > 0){
        invalidos();
    }
    else{

    printf("-- Historia --\n");
    Iterador it = devolveItHistoricoAux(m);
    
    if (!temSeguinteIterador(it)) {
        printf("  vazio\n");
        destroiIterador(it);
        return;
    }
    
    while (temSeguinteIterador(it)) {
        Registo r = seguinteIterador(it);
        printf("  Cliente %d: caixa %d, momento %d, pagou %d, peso %d\n", clienteRegisto(r), caixaRegisto(r), momentoRegisto(r), pagouRegisto(r), pesoRegisto(r));
    }
    destroiIterador(it);
    }
}

void cmdFimImediato(Supermercado m, string args){
	printf("Obrigado. Volte sempre!\n");
 
}

char lerComando(string linha) {
	printf("> ");
	if (fgets(linha, MAX_LINHA, stdin) == NULL)
		linha[0] = '.';
	return toupper(linha[0]);
}

void interpretador(Supermercado m ){
	char linha[MAX_LINHA], cmd;
	string args = linha + 2;
	do {
		cmd = lerComando(linha);
		switch (cmd){

            case '?': cmdMenu(m, args); break;
       
			case 'C': cmdCliente(m, args); break;
			case 'D': cmdAdicionaProdutoCestoCliente(m, args); break;
            case 'E': cmdListaClientes(m, args); break;

            case 'P': cmdCriaProdutoStock(m, args); break;
            case 'Q': cmdAcrescentaUnidadesProdutoStock(m, args); break;
            case 'R': cmdListaStock(m, args); break;

            case 'X': cmdAdicionaClienteCaixa(m, args); break;
            case 'Y': cmdAdicionaClienteMelhorCaixa(m, args); break;
            case 'Z': cmdListaCaixas(m, args); break;

            case 'T': cmdAvancaTempo(m, args); break;
            case 'H': cmdListaHistorico(m, args); break;

			case '.': cmdFimImediato(m, args); break;
			case '\n': break;
			default: printf("Comando desconhecido.\n"); break;
		}
	} while (cmd != 'F' && cmd != '.');
}

int main(void){

	Supermercado m = criaSupermercado();

	interpretador(m);

	destroiTudoSupermercado(m);
	
}

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/