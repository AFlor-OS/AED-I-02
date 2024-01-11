#ifndef FILA_H
#define FILA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct tno *tapontador;

typedef struct tno {
    int elem_f;
    tapontador prox_f;
} tno;

typedef struct {
    tapontador ini;
    tapontador fim;
    int count;
} t_fila;

int inicializa_fil(t_fila *F);
int enfileira_fil(int e, t_fila *F);
int desenfileira_fil(t_fila *F);
int vazia_fil(t_fila *F);
int conta_fil(t_fila *F);
void destruir_fil(t_fila *F);

#endif
