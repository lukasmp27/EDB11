#include <stdio.h>
#include <stdlib.h>

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

int main(){
    int vet[] = {65055372, 65919190, 65147145, 65892478, 65055214, 65452870};
    int tam = 6;

    radixsort(vet, tam);

    printf("VETOR EM ORDEM CRESCENTE:\n");
    for (int i = 0; i <= 5; i++){
        printf("[%i] ",vet[i]);
    }
}
