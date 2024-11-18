/*  Escreva um programa que leia um inteiro N(0 ≤ N ≤ 100), correspondente a ordem de
 uma matriz M de inteiros, e construa a matriz de acordo com o exemplo abaixo.
 Exemplos:
 • N=1
 1
 • N=2
 1 1
 1 1
 • N=3
 1 1 1
 1 2 1
 1 1 1
*/

#include <stdio.h>

#define NMAX 100

void le_matriz(int M[][NMAX], int n);
void printa_matrizQ(int M[][NMAX], int n);
void formata_matriz(int M[][NMAX], int n);

int main()
{   
    
    int matriz[NMAX][NMAX];
    int numero;

    printf("Entre com um número inteiro entre 0 e 100 que será o tamanho de sua matriz quadrada:\n");
    scanf("%d", &numero);

    le_matriz(matriz, numero);
    formata_matriz(matriz, numero);
    printa_matrizQ(matriz, numero);


    return 0;
}

//essa função recebe uma matriz vazia e preenche com valores 
void le_matriz(int M[NMAX][NMAX], int n) {
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            M[i][j] = 1;
        }    
    }
    printf("\n");

}

//essa função recebe uma matriz e imprime seus valores
void printa_matrizQ(int M[][NMAX], int n) {
    
    printf("Essa é a sua matriz: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

}

//Essa função recebe uma matriz quadrada formada por 1 e formata no padrao pedido;
void formata_matriz(int M[][NMAX], int n){
    
    for(int camada = 1; camada < (n+1)/2; camada++){
        for (int i = camada; i < n - camada; i++){
            for (int j = camada; j < n - camada; j++){
                M[i][j] = camada + 1;
            }  
        }
    }
}