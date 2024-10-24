/* Leia um número n, onde 1 ≤ n ≤ 10, e então leia uma matriz quadrada M[n][n]. Na
sequência, leia um caractere c. Caso c = “S
′′, calcule a soma dos elementos da diagonal principal da
matriz M. Caso c = “M′′, então calcule a média dos elementos que estão acima da diagonal superior.

*/

#include <stdio.h>

#define NMAX 100

void le_matrizQ(int M[][NMAX], int n);
void printa_matrizQ(int M[][NMAX], int n);
void calcula(int M[NMAX][NMAX], int n, char c);

int main()
{   
    
    int numero;
    int matriz[NMAX][NMAX];
    char c;
    
    printf("Entre com um número inteiro entre 0 e 100 que será o tamanho de sua matriz quadrada:\n");
    scanf("%d", &numero);
    printf("\n");
    getchar();
    le_matrizQ(matriz, numero);

    printf("Entre com 'S' caso você queira a soma dos elementos da diagonal principal da matriz ou M para calcular a media dos elementos que estão acima da diagonal superior:\n");
    scanf("%c", &c);
    getchar();
    printf("\n");

    
    calcula(matriz, numero, c);

    return 0;
}

//essa função recebe uma matriz vazia e preenche com valores 
void le_matrizQ(int M[NMAX][NMAX], int n) {
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Entre com um número:\n");
            scanf("%d", &M[i][j]);
            getchar();
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

//Essa função recebe uma matriz e um char caso o char for 'S'  Caso c = “S calcule a soma dos elementos da diagonal principal da matriz M. Caso c = “M′′, 
//então calcule a média dos elementos que estão acima da diagonal superior.
void calcula(int M[][NMAX], int n, char c){
    
    double resultado = 0;
    int cont = 0;
    if(c == 'S'){

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
               if(i == j){
                    resultado += M[i][j];
               } 
            }
        }

    }
    else{

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
               if(j >= i){
                    resultado += M[i][j];
                    cont++;
               } 
            }
        }
        resultado = resultado/cont;
    }

    printf("Resultado: %.2lf\n", resultado);

}