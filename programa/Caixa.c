/*
 *Caixas.c
 */

 #include "Caixa.h"

 typedef struct caixa {
    Info info;
    Fila Clientes; 
    int numClientes;
    int tempoCaixa;
    int idCaixa;
    int dinheiroCaixa;

 }*Caixa;

Caixa criaCaixa(void){
    Caixa c = malloc(sizeof(struct caixa));
    if (c == NULL) {
        semMemoria(); 
    }
    c->Clientes = criaFila(); 
    c->info = criaInfo("Caixa", destroiCaixa, destroiTudoCaixa, NULL, NULL, NULL);
    c->numClientes = 0; 
    c->tempoCaixa = 0;
    c->idCaixa = 0;
    c->dinheiroCaixa = 0;
    return c; 
}

void destroiCaixa(Caixa c){
    destroiFila(c->Clientes);
    c->numClientes = 0;
    c->tempoCaixa = 0;
    free(c);
}

void destroiTudoCaixa(Caixa c){
    destroiTudoFila(c->Clientes);
    c->numClientes = 0;
    c->tempoCaixa = 0;
    free(c);
}

void adicionaClienteCaixa(Caixa c, Cliente d){
    if (c == NULL){
        semMemoria();
    }
    acrescentaFila(c->Clientes, d); // acrescenta na fila o cliente

    int tempoCaixa1 = c->tempoCaixa;
    c->tempoCaixa = tempoCaixa1 + devolveTempoCliente(d);// adiciona tempo na caixa
    c->dinheiroCaixa += devolveDinheiroCliente(d);
    
}

bool existeClienteCaixa(Caixa c, Cliente d){

    if (c == NULL || d == NULL){
        return false;
    }
    Iterador it = iteradorFila(c->Clientes); //iterador de clientes
   
    while(temSeguinteIterador(it)){
        Cliente a = seguinteIterador(it);  //buscar um cliente
        if(comparaCliente(a, d) == 0){  //compara ambos clientes se for igual retorna 0 a funcao compara
            destroiIterador(it); 
            return true;
        }
    }
    destroiIterador(it);
    return false;
    
}

int devolveTempoCaixa(Caixa c){
    if(c == NULL){
        return -1;
    }
    return c->tempoCaixa;
}

int devolveIdCaixa(Caixa c){
    if(c == NULL){
        return -1;
    }
    return c->idCaixa;
}

void adicionaIdCaixa(Caixa c, int idCaixa){
    if(c == NULL){
        return;
    }
    c->idCaixa = idCaixa;
}

Iterador devolveItClienteCaixa(Caixa c){
    if (c == NULL ) {
        return NULL; 
    }

    Iterador it = iteradorFila(c->Clientes); // Iterador para a fila de clientes
    return it;
}

void removeClienteFila(Caixa c){
    if (c == NULL ) {
        return; 
    }
    removeFila(c->Clientes);
}

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/