/* Há muito tempo atrás, em uma galáxia muito, muito distante...
 Após odeclínio do Império, sucateiros estão espalhados por todo o universo procurando por um sabre
 de luz perdido. Todos sabem que um sabre de luz emite um padrão de ondas específico: 42 cercado
 por 7 em toda a volta. Você tem um sensor de ondas que varre um terreno com N x M células. Veja o
 exemplo abaixo para um terreno 4 x 7 com um sabre de luz nele (na posição (1, 3)).
 11 12 7 7 7 13 14
 15 6 7 42 7 7 42
 98-5 7 7 7 42 7-1 42 3 9 7 7 7
 Você deve escrever um programa que, dado um terreno N ×M, onde 1 ≤ N,M ≤ 20, procura pelo
 padrão do sabre de luz nele e reporte a coordenada de todos os sabres encontrados.

comandos para rodar no vscode

gcc -std=c99 -Wall -g -lm questao4.c -o questao4.exe
Get-Content input2.txt | ./questao4.exe
*/

#include <stdio.h>

#define NMAX 20

void le_matriz(int M[][NMAX], int n, int m);
void printa_matriz(int M[][NMAX], int n, int m);
int procura_sabre(int M[][NMAX], int l, int c, int i, int j);

int main()
{   
    
    int matriz[NMAX][NMAX];
    int numero, numero2;
    int encontrou_sabre = 0;
    scanf("%d %d", &numero, &numero2);

    le_matriz(matriz, numero, numero2);

    // os cantos não tem como ter matriz;
    for (int i = 1; i < numero - 1; i++) {
        for (int j = 1; j < numero2 - 1; j++) {
            if (procura_sabre(matriz, numero, numero2, i, j)) {
                printf("Sabre encontrado na posicao (%d, %d)\n", i, j);
                encontrou_sabre = 1;

            }
        }
    }

    if (!encontrou_sabre) {
        printf("Nenhum sabre encontrado\n");
    }

    return 0;
}

//essa função recebe uma matriz vazia e preenche com valores 
void le_matriz(int M[NMAX][NMAX], int n, int m) {
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &M[i][j]);
        }    
    }
    printf("\n");

}

//essa função recebe uma matriz e imprime seus valores
void printa_matriz(int M[][NMAX], int n, int m) {
    printf("Essa é a sua matriz: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

}

//Essa função recebe uma matriz lxn e procura o padrão de 42 no meio e 7 em volta para dizer se um sabre de luz foi encontrado na região
int procura_sabre(int M[][NMAX], int l, int c, int i, int j){
    
    if (M[i][j] != 42){
        return 0;
    }

    //isso verififca as 8 direções da matriz
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int k = 0; k < 8; k++){
        
        int posx_i = i + dx[k];
        int posy_j = j + dy[k];

        if(posx_i < 0 || posx_i >= l || posy_j < 0 || posy_j >= c || M[posx_i][posy_j] != 7){
            return 0;
        }

    }

    return 1;

}