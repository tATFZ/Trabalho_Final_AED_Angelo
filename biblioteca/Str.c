/*
 * Str.c
 */

#include "Str.h"

/*------------------------------------------*/
/* Tipo privado */

struct Str {
	Info info;
	string valor;
};

/*------------------------------------------*/
/* Funcoes publicas */

Str criaStr(string valor){
	Str str = malloc(sizeof(struct Str));
	if (str == NULL) semMemoria();
	str->info = criaInfo("Str", destroiStr, destroiStr,
				comparaStr, dispersaoStr, textoStr);
	str->valor = criaString(valor);
	return str;
}

void destroiStr(Str str){
	destroiString(str->valor);
	free(str);
}

int comparaStr(Str str1, Str str2){
	string s1 = valorStr(str1);
	string s2 = valorStr(str2);
	return strcmp(s1, s2);
}

/* djb2 function by dan bernstein */
int dispersaoStr(Str str, int dim){
	string s = valorStr(str);
    unsigned long hash = 5381;
	int c;
	while ((c = (unsigned int)*s++) != '\0')
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash % dim;
}

string textoStr(Str str){
	return str->valor;
}

string valorStr(Str str){
	return str->valor;
}

void testeStr(void){
	printf("Testando Str:\n");
	Str strx = criaStr("05");
	for (int i = 0 ; i < 10 ; i++){
		char a[100];
		sprintf(a, "%02d", i);
		Str str = criaStr(a);
		printf("(%s,%d,%d)\n",
			textoStr(str),
			comparaStr(str, strx),
			dispersaoStr(str, 100)
		);
		destroiStr(str);
	}
	destroiStr(strx);
	printf("\n");
}

