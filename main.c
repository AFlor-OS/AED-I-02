#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int main() {
    int N;
    scanf("%d", &N);

    char respostas[N][12]; 

    t_pilha pilha;
    t_fila fila;

    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);

        inicializar_pil(&pilha);
        inicializa_fil(&fila);
        int isPilha = 1;  
        int isFila = 1; 

        for (int j = 0; j < K; j++) {
            char op;
            int val;
            scanf(" %c %d", &op, &val);

            if (op == 'i') {
                push(val, &pilha);
                enfileira_fil(val, &fila);
            } else if (op == 'r') {
                if (pop(&pilha) != val) {
                    isPilha = 0;
                }
                int fila_desenfileirar = desenfileira_fil(&fila);
                if (fila_desenfileirar != val) {
                    isFila = 0;
                }
            }
        }

        if (isPilha && !isFila) {
            strcpy(respostas[i], "pilha");
        } else if (!isPilha && isFila) {
            strcpy(respostas[i], "fila");
        } else if (!isPilha && !isFila) {
            strcpy(respostas[i], "impossivel");
        } else {
            strcpy(respostas[i], "indefinido");
        }

        if (!vazia_fil(&fila)) {
           	while(desenfileira_fil(&fila) != -1){
         		desenfileira_fil(&fila);
           	}
    	}

    	if (!vazia_pil(&pilha)) {
           	while(pop(&pilha) != -1){
         		pop(&pilha);
           	}
    	}
    	
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", respostas[i]);
    }

    return 0;
}
