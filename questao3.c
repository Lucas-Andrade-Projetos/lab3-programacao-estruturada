/* Escreva um programa que dada uma matriz 9 x 9 preenchida, verifique se ela é uma solução válida do
Sudoku.
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
    
    int cont = 0;

    //verifica linhas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[cont][j] == M[i][j] && cont != j){
                printf("%d %d %d\n", i, j, M[i][j]);
                //printf("%d %d %d\n", M[8][0], M[8][2], M[i][j]);
                printf("Solucao invalida.\n");
                return;
            }
        }
        cont++;
    }

    //verifica colunas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[0][i] == M[j][i] && 0 != j){
                printf("%d %d %d\n", i, j, M[i][j]);
                //printf("%d %d %d\n", M[8][0], M[8][2], M[i][j]);
                printf("Solucao invalida.\n");
                return;
            }
        }
    }

    printf("Solucao valida.\n");

}