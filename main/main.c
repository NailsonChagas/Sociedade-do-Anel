#define INT_MAX 2147483647

#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

int verifica_movimento(int **m, int l, int c, int *pL, int *pC){
    int cont = 0;
        
    //se já estiver no vulcão retornar 0
    if(*pL == (l-1) && *pC == (c-1)){
        return 0;
    }
        
    if((*pL - 1) >= 0 && m[*pL - 1][*pC] != INT_MAX){
        cont++;
    }
    if((*pL + 1) < l && m[*pL + 1][*pC] != INT_MAX){
        cont++;
    }
    if((*pC - 1) >= 0 && m[*pL][*pC - 1] != INT_MAX){
        cont++;
    }
    if((*pC + 1) < c && m[*pL][*pC + 1] != INT_MAX){
        cont++;
    }

    if(cont > 0){//pode se mexer: retornar 1
        return 1;
    }
    else{//impossivel se mexer: retornar -1
        return -1;
    }
}

//anula a casa em bilbo esta -> verifica que posições pode de mover -> verifica para qual posição ira se mover -> ... 
//... -> move sua posição -> retorna o valor da posição em que bilbo parou
int movendo_bilbo(int **m, int l, int c, int *pL, int *pC){
    int cima = INT_MAX, baixo = INT_MAX, esquerda = INT_MAX, direita = INT_MAX;
    int valorDaCasa = -1;
    
    //primeiro anulando o valor da casa em que bilbo está
    m[*pL][*pC] = INT_MAX;

    //verificando para onde bilbo ira se mover
    if((*pL - 1) >= 0 && m[*pL - 1][*pC] != INT_MAX){
        cima = m[*pL - 1][*pC];
    }
    if((*pL + 1) < l && m[*pL + 1][*pC] != INT_MAX){
        baixo = m[*pL + 1][*pC];
    }
    if((*pC - 1) >= 0 && m[*pL][*pC - 1] != INT_MAX){
        esquerda = m[*pL][*pC - 1];
    }
    if((*pC + 1) < c && m[*pL][*pC + 1] != INT_MAX){
        direita = m[*pL][*pC + 1];
    }

    //verificando para qual ira se mover e movendo bilbo
    if(cima != INT_MAX && (cima < baixo && cima < esquerda && cima < direita)){
        *pL = *pL - 1;
        valorDaCasa = m[*pL][*pC];
    }
    else if(baixo != INT_MAX && (baixo < cima && baixo < esquerda && baixo < direita)){
        *pL = *pL + 1;
        valorDaCasa = m[*pL][*pC];
    }
    else if(esquerda != INT_MAX && (esquerda < baixo && esquerda < cima && esquerda < direita)){
        *pC = *pC - 1;
        valorDaCasa = m[*pL][*pC];
    }
    else if(direita != INT_MAX && (direita < baixo && direita < cima && direita < esquerda)){
        *pC = *pC + 1;
        valorDaCasa = m[*pL][*pC];
    }

    //retornado o valor da casa em que bilbo parou
    return valorDaCasa;
}

//vai retornar a soma total caso tenha chegado a vulcão ou -1 caso tenho ocorrido um erro
int somando_caminho_bilbo(int **m, int l, int c){
    int posLinha = 0, posColuna = 0, somaTotal = 0;

    while(verifica_movimento(m, l, c, &posLinha, &posColuna) == 1){
        somaTotal = somaTotal + movendo_bilbo(m, l, c, &posLinha, &posColuna);
    }

    if(verifica_movimento(m, l, c, &posLinha, &posColuna) == -1){
        somaTotal = -1;
    }

    return somaTotal;
}

int main(void){
    int i, j, nLinhas, nColunas, **matriz, resultado;

    scanf("%d %d", &nLinhas, &nColunas);
    matriz = alocar_matriz_int(nLinhas, nColunas);

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("Linha[%d] Coluna[%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    resultado = somando_caminho_bilbo(matriz, nLinhas, nColunas);

    if(resultado == -1){
        printf("\nsem solucao");
    }
    else{
        printf("\nResultado: %d", resultado);
    }

    desalocar_matriz_int(matriz, nLinhas);

    return 0;
}