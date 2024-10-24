/* Escreva um programa que dada uma matriz 9 x 9 preenchida, verifique se ela é uma solução válida do
Sudoku.

comandos para rodar no vscode

gcc -std=c99 -Wall -g -lm questao3.c -o questao3.exe
Get-Content input.txt | ./questao4.exe
*/

#include <stdio.h>

#define NMAX 100

void le_matrizSoduku(int M[][NMAX], int n);
void printa_matrizQ(int M[][NMAX], int n);
void verifica_sudoku(int M[][NMAX], int n);

int main()
{   
    
    int matriz[NMAX][NMAX];
    
    le_matrizSoduku(matriz, 9);

    verifica_sudoku(matriz, 9);

    return 0;
}

//essa função recebe uma matriz vazia e preenche com valores 
void le_matrizSoduku(int M[NMAX][NMAX], int n) {
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &M[i][j]);
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

//Essa função recebe uma matriz 9x9 e verifica se é uma solução de sudoku
void verifica_sudoku(int M[][NMAX], int n){
    
    //verifica linhas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++){
                if (M[i][j] == M[i][k]){
                    //printf("%d %d %d %d\n", i, j, k,M[i][j]);
                    printf("Solucao invalida.\n");
                    return;
                }
            }
        }
    }

    //verifica Coluna
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++){
                if (M[j][i] == M[k][i]){
                    //printf("%d %d %d %d\n", i, j, k,M[i][j]);
                    printf("Solucao invalida.\n");
                    return;
                }
            }
        }
    }

    //verifica 3x3 aqui eu uso um array prenchido com 0 e ele vai se preenchendo com 1 conforme vão aparecendo os números caso o numero se repita o 1 
    //bate no == 1 e dá como repetido
    for(int lin_ini = 0; lin_ini < n; lin_ini+=3){
       for(int col_ini = 0; col_ini < n; col_ini+=3){

        int checa_numero[10] = {0};

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                     
                     int numero = M[lin_ini + i][col_ini + j];

                    if (checa_numero[numero] == 1) {
                        printf("Solução inválida (erro na subgrade).\n");
                        return;
                    }

                    checa_numero[numero] = 1;
                }
            }

        }
    }

    printf("Solucao valida.\n");

}