#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"

int inicializa_fil(t_fila *F) {

    F->ini = NULL;
    F->fim = NULL;
    F->count = 0;
    return SUCESSO;

}

int enfileira_fil(int e, t_fila* F){

    tapontador t = (tapontador)malloc(sizeof(tno));

    if(F == NULL){
        printf("Fila (memoria) cheia!\n");
        return CHEIA;
    }

    t->elem_f = e;
    t->prox_f = NULL;

    if(F->fim == NULL){
        F->ini = t;
    }
    else{
        F->fim->prox_f = t;
    }
    F->fim = t;
    F->count++;
    return SUCESSO;
}

int desenfileira_fil(t_fila *F) {
    if (vazia_fil(F)) {
        return NAO_EXISTE;
    }

    tapontador t = F->ini;
    F->ini = F->ini->prox_f;

    if (F->ini == NULL) {
        F->fim = NULL;
    }

    int e = t->elem_f;
    free(t);
    F->count--;

    if (F->ini == NULL && F->fim == NULL) {
        F->count = 0;
    }

    return e;
}

int vazia_fil(t_fila *F) {
    if (F->ini == NULL && F->fim == NULL) {
        return VAZIA;
    }
    return 0;
}


int contar_fil(t_fila *F){
    return F->count;
}

void destruir_fil(t_fila *F) {
    free(F);
}