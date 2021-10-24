#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

int* alocar_vetor_int(int n){
    int *v = NULL;

    if(n > 0){
        v = (int*)malloc(sizeof(int) * n);
    }

    return v;
}

int** alocar_matriz_int(int l, int c){
    int **m = NULL;

    if(l>0 && c>0){
        int i;

        m = (int**)malloc(sizeof(int*) * l);
        
        for(i=0; i<l; i++){
            m[i] = (int*)malloc(sizeof(int) * c);
        }
    }

    return m;
}

void imprimir_vetor_int(int *v, int n){
    if(v != NULL){
        int i;

        printf("Vetor[%d]:", n);
        for(i=0; i<n; i++){
            printf(" %d", v[i]);
        }
        printf("\n");
    }
    else{
        printf("\nVETOR INVALIDO\n");
    }
}

void imprimir_matriz_int(int **m, int l, int c){
    if(m != NULL){
        int i, j;

        printf("Matriz[%d][%d]:\n", l, c);
        for(i=0; i<l; i++){
            for(j=0; j<c; j++){
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\nMATRIZ INVALIDA\n");
    }
}

void desalocar_vetor_int(int *v){
    if(v != NULL){
        free(v);
    }
}

void desalocar_matriz_int(int **m, int l){
    if(m != NULL){
        int i;

        for(i=0; i<l; i++){
            free(m[i]);
        }

        free(m);
    }
}