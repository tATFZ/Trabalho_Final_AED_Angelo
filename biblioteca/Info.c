/*
 * Info.c
 */

#include "Info.h"

/* Entender este ficheiro nao faz parte dos objetivos de AED.
   Mas se voce tiver curiosidade de o estudar, isso e' positivo. */

/*------------------------------------------*/
/* Tipo privado */

struct Info {
	string tipo;
	void (*destroi)(obj ob);
	void (*destroiTudo)(obj ob);
	int (*compara)(obj ob1, obj ob2);
	int (*dispersao)(obj ob, int dim);
	string (*texto)(obj ob);
};

/*------------------------------------------*/
/* Tabela de infos privada */

#define FATOR_DE_CAPACIDADE	4
#define INTERVALO	('Z' - 'A' + 1)
#define CAPACIDADE	(INTERVALO * FATOR_DE_CAPACIDADE)

static Info tabelaInfos[CAPACIDADE] = {}; // inicializa tudo a NULL

static int dispersaoInfo(string tipo){
	char c = tipo[0];
	if (!isupper(c))
		erroFatal("O tipo dum objeto tem de comecar por maiuscula");
	return (c - 'A') * FATOR_DE_CAPACIDADE;
}

static int slotInfo(string tipo){ // usa dispersao fechada
	int d = dispersaoInfo(tipo);
	int cap = CAPACIDADE;
	for (int i = d; i < cap; i++){
		if (tabelaInfos[i] == NULL
		|| strcmp(tabelaInfos[i]->tipo, tipo) == 0)
			return i;
	}
	for (int i = 0; i < d; i++){
		if (tabelaInfos[i] == NULL
		|| strcmp(tabelaInfos[i]->tipo, tipo) == 0)
			return i;
	}
	erroFatal("A tabela de Infos ficou cheia");
	return -1; // para evitar warning
}

static Info procuraInfo(string tipo){
	return tabelaInfos[slotInfo(tipo)];
}

static void acrescentaInfo(Info info){
	tabelaInfos[slotInfo(info->tipo)] = info;
}

/*------------------------------------------*/
/* Funcoes privadas */

static void destroiTudo0(obj ob){
	aviso("Chamou a funcao indefinida 'destroiTudo%s'", tipo(ob));
}

static int compara0(obj ob1, obj ob2){
	aviso("Chamou a funcao indefinida 'compara%s'", tipo(ob1));
	return 0;
}

static int dispersao0(obj ob, int dim){
	aviso("Chamou a funcao indefinida 'dispersao%s'", tipo(ob));
	return 0;
}

static string texto0(obj ob){
	aviso("Chamou a funcao indefinida 'texto%s'", tipo(ob));
	return "";
}

static void preencheTipo(Info info, string tipo){
	if (tipo == NULL || strcmp(tipo, "") == 0)
		erroFatal("Na criacao dum bloco informativo, e' "
			"obrigatorio indicar um tipo");
	info->tipo = criaString(tipo);
}

static void preencheDestroi(Info info, void (*destroi)(obj ob)){
	if (destroi == NULL)
		erroFatal("Na criacao dum bloco informativo, e' "
			"obrigatorio indicar uma funcao 'destroi'");
	info->destroi = destroi;
}

static void preencheDestroiTudo(Info info, void (*destroiTudo)(obj ob)){
	if (destroiTudo == NULL)
		info->destroiTudo = destroiTudo0;
	else
		info->destroiTudo = destroiTudo;
}

static void preencheCompara(Info info, int (*compara)(obj ob1, obj ob2)){
	if (compara == NULL)
		info->compara = compara0;
	else
		info->compara = compara;
}

static void preencheDispersao(Info info, int (*dispersao)(obj ob, int dim)){
	if (dispersao == NULL)
		info->dispersao = dispersao0;
	else
		info->dispersao = dispersao;
}

static void preencheTexto(Info info, string (*texto)(obj ob)){
	if (texto == NULL)
		info->texto = texto0;
	else
		info->texto = texto;
}

static Info info(obj ob){
	return *((Info *)ob);
}

/*------------------------------------------*/
/* Funcoes publicas */

Info criaInfo(string tipo, void *destroi, void *destroiTudo,
			void *compara, void *dispersao, void *texto){
	Info info = procuraInfo(tipo);
	if (info != NULL)	// ja' existe
		return info;
	info = malloc(sizeof(struct Info));	// cria novo
	if (info == NULL) semMemoria();
	preencheTipo(info, tipo);
	preencheDestroi(info, destroi);
	preencheDestroiTudo(info, destroiTudo);
	preencheCompara(info, compara);
	preencheDispersao(info, dispersao);
	preencheTexto(info, texto);
	acrescentaInfo(info);	// instala novo
	return info;
}

bool mesmoTipo(obj ob1, obj ob2){
	return strcmp(tipo(ob1), tipo(ob2)) == 0;
}

string tipo(obj ob){
	return info(ob)->tipo;
}

void destroi(obj ob){
	info(ob)->destroi(ob);
}

void destroiTudo(obj ob){
	info(ob)->destroiTudo(ob);
}

int compara(obj ob1, obj ob2){
	return info(ob1)->compara(ob1, ob2);
}

int dispersao(obj ob, int dim){
	return info(ob)->dispersao(ob, dim);
}

string texto(obj ob){
	return info(ob)->texto(ob);
}
