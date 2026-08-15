/*
Supermercado.c
*/

#include"Supermercado.h"

#define MAX_LINHA 64
#define CAIXA_ESPECIAL 0

typedef struct supermercado{
    Info info;
    Stock stock;
    GerirClientes GerirClientes;
    GerirCaixas GerirCaixas;
    Historia historia;
    int tempoSupermercado;

}*Supermercado;

Supermercado criaSupermercado(void){  
    Supermercado m = malloc(sizeof(struct supermercado));
    if (m == NULL) {
        semMemoria();
    }
    m ->info = criaInfo("Supermercado", destroiTudoSupermercado, destroiTudoSupermercado, NULL, NULL, NULL);
    m->stock = criaStock(); 
    m->GerirClientes = cria_GC(); 
    m->GerirCaixas = criaGerirCaixas();
    m->historia = criaHistoria();
    m->tempoSupermercado = 0;
    return m;
}

// Utilizado para criar um produto no stock 

bool existeProdutoStockAux(Supermercado m, string nome){

    if (existeChave(m->stock, nome)) { // Verifica se o produto existe
        return true;
    }else {
        return false;
    }
}

void criaProdutoStockAux(Supermercado m, string nome, int quantidade, int preco, int peso){
    if (m == NULL || nome == NULL) {
        return; // Verifica se o supermercado e o produto existem
    }
    criaProdutoStock(m->stock, nome, quantidade, preco, peso); // Adiciona o produto ao stock
}

// utilizado para adicionar x unidades ao produto no stock

void acrescentaUnidadesProdutoStockAux(Supermercado m, string nome, int quantidade){
    if (m == NULL || nome == NULL) {
        return; 
    }
    acrescentaUnidadesProdutoStock(m->stock, nome, quantidade); // Adiciona x unidades ao produto no stock
}

// Utilizado para listar o stock

bool temStockAux(Supermercado m){
    if (temStock(m->stock)) { 
        return true;
    } else {
        return false;
    }
}

Produto devolveProdutoStockAux(Supermercado m, string chave){
    if (m == NULL || chave == NULL) {
        return NULL; // Verifica se o supermercado e o produto existem
    }
    Produto p = devolveProdutoStock(m->stock, chave); // Devolve o produto do stock
    return p;
}

Iterador listaStockAux(Supermercado m){
    if (m == NULL) {
        return NULL; 
    }
    Iterador it = listaStock(m->stock); // Devolve o iterador ordenado das chaves do stock
    return it;
}


void destroiTudoSupermercado(Supermercado m){
    if (m == NULL) {
        return; // Verifica se o supermercado existe
    }
   
    destroiTudoStock(m->stock); 
    destroiTudo_GC(m->GerirClientes); 
    destroiTudo_GerirCaixas(m->GerirCaixas); 
    destroiTudoHistoria(m->historia);
    free(m);
}

// Utilizado para o criaCliente

void adicionaClienteSupermercadoAux(Supermercado m){ 
    if (m == NULL){
            return;
    }
    adicionaCliente_GC(m ->GerirClientes); // Adiciona o cliente ao dicionario de clientes
 }

int numeroAtualClienteAux(Supermercado m){  
    if (m == NULL){
        return -1;
    }
    int j = 0;
    j = (numeroAtualClienteGC(m->GerirClientes)); // Obtem o numero do cliente
    return j; // Devolve o numero atual do cliente
}

void adicionaProdutoCestoClienteAux(Supermercado m, string nome, int numCliente, int quantidade){

    if (m == NULL || numCliente < 0 || numCliente < 0) {
        return;      
    }

    string chave = strdup(nome);

    Produto produto_stock = devolveProdutoStock(m->stock, chave);
    int novaQuantidadeStock = (devolveQuantidadeProduto(produto_stock) - quantidade);
    alteraQuantidadeProduto(produto_stock, novaQuantidadeStock);

    if(existeProdutoCestoGC(m->GerirClientes, numCliente, chave)){ //se existe entao altera a quantidade
        
        alteraQuantidadeProdutoGC(m->GerirClientes, quantidade, numCliente, chave);

        Produto p = devolveProdutoCestoGC(m->GerirClientes, numCliente, chave);// adiciona tempo cliente
        int adicionaTempo = tempoProduto(p, quantidade);
        adicionaTempoClienteGC(m->GerirClientes, adicionaTempo, numCliente);

        int novoDinheiro = devolvePrecoProduto(p) * quantidade;  
        adicionaDinheiroClienteGC(m->GerirClientes, novoDinheiro, numCliente);

        free(chave);

    } else{ //se nao existe cria um produto com a quantidade desejada

        string nome_produto = devolveNomeProduto(produto_stock);
        int preco = devolvePrecoProduto(produto_stock);  //dados do produto a adicionar no cesto
        int peso = devolvePesoProduto(produto_stock);

        Produto produto_cesto = criaProduto(nome_produto, quantidade, preco, peso);

        adicionaProdutoCestoGC(m->GerirClientes, numCliente, produto_cesto, chave);
        
        Produto p = devolveProdutoCestoGC(m->GerirClientes, numCliente, chave);// adiciona tempo cliente
        int adicionaTempo = tempoProduto(p, quantidade);
        adicionaTempoClienteGC(m->GerirClientes, adicionaTempo, numCliente);

        int novoDinheiro = devolvePrecoProduto(p) * quantidade;  
        adicionaDinheiroClienteGC(m->GerirClientes, novoDinheiro, numCliente);

        free(chave);
    }
}

bool temCaixas(Supermercado m) {
    //se há pelo menos 1 caixa, retorna true
    return devolveNumeroGerirCaixas(m->GerirCaixas) > 0;
}

Cliente devolveClienteGCAux(Supermercado m, int cliente) {
    return devolveClienteGC(m->GerirClientes, cliente);
}

Iterador devolveIteradorOrdenadoChaveGCAux(Supermercado m) {
    return devolveIteradorOrdenadoChaveGC(m->GerirClientes);
}

GerirClientes devolveGerirClientesSupermercado(Supermercado m) {
    return m->GerirClientes;
}

GerirCaixas devolveGerirCaixasSupermercado(Supermercado m) {
    return m->GerirCaixas;
}

//Usado para o void cmdAdicionaClienteCaixa

bool cestoVazioClienteGCAux(Supermercado m, int numCliente){
    if(cestoVazioClienteGC(m->GerirClientes, numCliente)){
        return true;
    }
    else{
        return false;
    }
}

bool existeClienteGerirCaixasAux(Supermercado m, int numCliente){
    if(m == NULL){
        return false;
    }

    Cliente d = devolveClienteGC(m->GerirClientes, numCliente);// vai buscar o cliente 

    if(existeClienteGerirCaixas(m->GerirCaixas, d)){ //vai verificar se o cliente ja esta numa caixa
        return true;
    }

    return false;
}

void adicionaClienteCaixaAux(Supermercado m, int numCaixa, int numCliente){
    if(m == NULL){
        return;
    }
    Cliente d = devolveClienteGC(m->GerirClientes, numCliente); //vai buscar o cliente
    adicionaClienteGerirCaixas(m->GerirCaixas, d, numCaixa); // adiciona o cliente d na caixa escolhida
}

int devolveNumeroGerirCaixasAux(Supermercado m){
    if(m == NULL){
        return -1;
    }
    return devolveNumeroGerirCaixas(m->GerirCaixas);
}

// usado para o adicionaClienteMelhorCaixa

int melhorTempoGerirCaixasAux(Supermercado m, int numCliente){
    int cestovazio = 0;
    if(m == NULL){
        return -1;
    }

     if(cestoVazioClienteGC(m->GerirClientes, numCliente)){ //se cesto estiver vazio 
        cestovazio = 1;
    } else{
        cestovazio = 0;
    }
    return melhorTempoGerirCaixas(m->GerirCaixas, cestovazio);
}

void alteraCaixaGCAux(Supermercado m, int numCliente, int caixaCliente){
    if(m == NULL){
        return;
    }
    alteraCaixaGC(m->GerirClientes, numCliente, caixaCliente);
}

int devolveIdCaixaGCAux(Supermercado m, int numCliente){
    if(m == NULL){
        return -1;
    }
    return devolveIdCaixaGC(m->GerirClientes, numCliente);
}

Caixa devolveCaixaGerirCaixasAux(Supermercado m, int idCaixa) {
    if (m == NULL) {
        return NULL; // Verifica se o supermercado existe
    }
    return devolveCaixaGerirCaixas(m->GerirCaixas, idCaixa); // Devolve a caixa com o id indicado
}

int devolveDinheiroClienteAux(Cliente c){
    if( c == NULL){
        return -1;
    }
    return devolveDinheiroCliente(c);
}

// usado para tentar avancar no tempo

void avancaTempoSupermercado(Supermercado m, int avancaTempo){
    if (m == NULL) {
        return; 
    }
    for (int segundo = 0; segundo < avancaTempo; segundo++){ //para avancar o tempo em paralelo

        int numCaixas = devolveNumeroGerirCaixas(m->GerirCaixas);

        for (int i = 0; i < numCaixas; i++){
            passaUmSegundoCaixaSupermercado(m, i);
        }
        m->tempoSupermercado++;
    }
}

void passaUmSegundoCaixaSupermercado(Supermercado m, int idCaixa){
    if (m == NULL){
        return;
    }
    Caixa c = devolveCaixaGerirCaixas(m->GerirCaixas, idCaixa);
    if (c == NULL){
        return;
    } 

    bool caixaEspecial;
    if (idCaixa == CAIXA_ESPECIAL){ //Se a caixa e' 0 entao pode 'processar' varios clientes ao mesmo tempo ou seja nao precisam de esperar
        caixaEspecial = true;
    } 
    else {
        caixaEspecial = false;
    }

    bool clientesProcessados = true;

    while (clientesProcessados){
        clientesProcessados = false;
        Iterador it = devolveItClienteCaixa(c);
        
        if (temSeguinteIterador(it)){ // verificamos se existe um cliente na fila

            Cliente cliente = seguinteIterador(it);
            destroiIterador(it);

            int novoTempo = devolveTempoCliente(cliente) - 1;  // reduzimos o tempo de espero do cliente de 1 segundo
            alteraTempoCliente(cliente, novoTempo);

            if (novoTempo <= 0){ // verifica se o tempo de atendimenteo ja acabou

                adicionaRegistoAux(m, devolveIdCliente(cliente), idCaixa, m->tempoSupermercado + 1, devolveDinheiroCliente(cliente),devolvePesoCliente(cliente));

                removeClienteGerirCaixas(m->GerirCaixas, idCaixa);   
                removeClienteGC(m->GerirClientes, devolveIdCliente(cliente));

                clientesProcessados = caixaEspecial;  // se caixa e' 0 entao ira continuar a 'processar'
            }
        } 
        else{
            destroiIterador(it);
            break;
        }
    }
}

int devolveTempoSupermercado(Supermercado m){
    if (m == NULL) {
        return -1;
    }
    return m->tempoSupermercado;
}

void adicionaRegistoAux(Supermercado m, int cliente, int caixa, int momento, int pagou, int peso){
    if (m == NULL){
        return;
    }
    
    Registo r = criaRegisto(cliente, caixa, momento, pagou, peso);
    acrescentaHistoria(m->historia, r);
}

void listaHistoricoAux(Supermercado m){
    if (m == NULL){
        return;
    }

    printf("-- Historia --\n");
    Iterador it = iteradorHistoria(m->historia);
    
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

Iterador devolveItHistoricoAux(Supermercado m){
    if (m == NULL){
        return NULL;
    }
    Iterador it = iteradorHistoria(m->historia);
    return it;
}

bool existeClienteGCAux(Supermercado m){
    if (m == NULL){
        return false;
    }
    return existeClienteGC(m->GerirClientes);
}

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/