/* Neste exercício, você vai implementar o algoritmo de busca binária em um vetor ordenado. Mais precisamente, você deve implementar a 
função abaixo que implementa esse algoritmo.
// @valores é um vetor contendo n números ordenados de forma não decrescente,
// ou seja, valores[0] <= valores[1] <= valores[2] <= ...
// @n é a variável que diz quantos valores estão no vetor
// @chave é um número inteiro
// Retorno: Retorna o menor valor de i tal que valores[i] == chave.
// Caso o valor de @chave não esteja contido em @valores, retorna -1
int busca_binaria(int valores[], int n, int chave);*/
#include <stdio.h>

void prencheVetor(int lista[], int n);
int busca(int valores[], int n, int j, int chave);
void ordena(int valores[], int n);

#define NMAX 1000

int main()
{
    int numero, chave, resultado;
    int lista1[NMAX]; 

    printf("Entre com um número inteiro que será o tamanho de seu vetor:\n");
    scanf("%d", &numero);
    printf("\n");

    prencheVetor(lista1, numero);
    
    printf("Entre com um número inteiro que será a chave que você está verificando:\n");
    scanf("%d", &chave);
    printf("\n");

    ordena(lista1, numero);
    resultado = busca(lista1, 0, numero - 1, chave);
    printf("%d\n", resultado);
    
    return 0;
}

/*Essa função popula um vetor de tamanho n*/
void prencheVetor(int lista[], int n) {
    
    for (int i = 0; i < n; i++) {
        printf("Entre com um número:\n");
        scanf("%d", &lista[i]);
        printf("\n");
    }

}

/*Essa função lê o vetor e um numero chave e verifica se a chave está no vetor*/
int busca(int valores[], int n, int j, int chave) {
    
    int meio = (n + j)/2;
    if(valores[meio] == chave){
        return meio;
    }

    if (n >= j)
    {
        return -1;  
    }else 
        if(valores[meio] < chave){
            return busca(valores, meio + 1, j, chave); // estou dizendo que a chave está no lado direito do vetor 
        }else{
            return busca(valores, 0, meio - 1, chave); // estou dizendo que a chave está no lado esquerdo do vetor 
        }
    
    printf("\n");
}

/*Essa função lê o vetor e um numero e ordena o vetor em ordem crescente*/
void ordena(int valores[], int n) {
    
    int valor, i, j;
    
    for (i = 1; i < n; i++)
    {
        j = i;
        while ((j != 0) && (valores[j] < valores[j - 1]))
        {
            valor = valores[j];
            valores[j] = valores[j - 1];
            valores[j - 1] = valor; 
            j--;
        }      
    }

}