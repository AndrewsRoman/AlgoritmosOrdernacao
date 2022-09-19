#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

#define TAM 10;

void cria_vetor(int vetor[], int n){  //CRIA VETOR MANUALMENTE  
                                      
    int i;
    for (i=0;i<n;i++){
        printf("insira insira um numero para o vetor[%d]: ", i);
        scanf("%d",&vetor[i]);
    }
}
void preenche_vetor(int vetor[],int tamvetor){ // PREENCHE VETOR COM VALORES PSEUDO ALEATORIOS
	for (int i = 0; i < tamvetor; i++){
		vetor[i] = (rand()%1000);
	}
}

void imprime_vetor(int vetor[], int tamvetor){
	for (int i=0;i < tamvetor; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");

}	

void verifica_ordenacao(int vetor[], int tam){
	 int ordenacao = 1;
	for (int i=0; i<tam-1; i++){
		if (vetor[i] > vetor[i+1]){
			ordenacao = 0;
		}
	}
	if (ordenacao)
		printf("Ordenado\n");
	else
		printf("Ordenacao FALHOU\n");
	
}

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int *numComp;
	int tamvetor;
	tamvetor = TAM;

	int* vetor = malloc(tamvetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	
	clock_t start, end;//variáveis do tipo clock_t
    double total;

	
	int valor;
	printf("insira um valor para procurar dentro do vetor:\n");
	scanf("%d", &valor);
	
	// BUSCA SEQUENCIAL //
		printf("\n");
	printf("// BUSCA SEQUENCIAL //\n");
	preenche_vetor(vetor, tamvetor);
	imprime_vetor(vetor, tamvetor);
	//verifica_ordenacao(vetor,tamvetor);
	numComp = 0;
	start = clock();
	idxBusca = buscaSequencial(vetor, tamvetor-1, valor, &numComp);
	
	end = clock();	
	if (idxBusca != -1)
		printf("o valor %d foi encontrado na posição %d \n", valor, idxBusca);
	else 
		printf("o valor %d não esta presente no vetor\n", valor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do Busca Sequencial: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComp);
	printf("\n");
	
	
	// BUSCA BINARIA //
	printf("\n");
	printf("// BUSCA BINARIA //\n");
	int numComparacoes;
	preenche_vetor(vetor, tamvetor);
	imprime_vetor(vetor, tamvetor);
	numComp = selectionSort(vetor, tamvetor);// usado para ordenar o vetor para poder aplicar a busca binaria
	imprime_vetor(vetor, tamvetor);
	verifica_ordenacao(vetor,tamvetor);
	
	numComparacoes=0;
	start = clock();
	idxBusca = buscaBinaria(vetor, tamvetor, valor, &numComparacoes);
	end = clock();
	if (idxBusca != -1)
		printf("o valor %d foi encontrado na posição %d \n", valor, idxBusca);
	else 
		printf("o valor %d não esta presente no vetor\n", valor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do Busca Binaria: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComparacoes);
	printf("\n");
	
	
	// SELECTION SORT //
	printf("\n");	
	printf("// SELECTION SORT //\n");
	preenche_vetor(vetor, tamvetor);
	//imprime_vetor(vetor, tamvetor);
	numComp=0;
	start = clock();
	numComp = selectionSort(vetor, tamvetor);
	end = clock();
	//imprime_vetor(vetor, tamvetor);
	verifica_ordenacao(vetor,tamvetor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do Selection Sort: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComp);
	printf("\n");
	
	
	// MERGE SORT //
	printf("\n");
	printf("// MERGE SORT //\n");
	preenche_vetor(vetor, tamvetor);
	//imprime_vetor(vetor, tamvetor);
	numComp=0;
	start = clock();
	numComp = mergeSort(vetor, tamvetor);
	end = clock();
	//imprime_vetor(vetor, tamvetor);
	verifica_ordenacao(vetor,tamvetor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do MergeSort: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComp);
	printf("\n");
	
	
	// INSERTION SORT //
	printf("\n");
	printf("// INSERTION SORT //\n");
	preenche_vetor(vetor, tamvetor);
	//imprime_vetor(vetor, tamvetor);
	
	start = clock();
	numComp = insertionSort(vetor, tamvetor-1);
	end = clock();
	//imprime_vetor(vetor, tamvetor);
	verifica_ordenacao(vetor,tamvetor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do insertionSort: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComp);
	printf("\n");
	
	// QUICK SORT //
	printf("\n");
	printf("// QUICK SORT //\n");
	preenche_vetor(vetor, tamvetor);
	//imprime_vetor(vetor, tamvetor);
	
	start = clock();
	numComp = quickSort(vetor, tamvetor);
	end = clock();
	//imprime_vetor(vetor, tamvetor);
	verifica_ordenacao(vetor,tamvetor);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("tempo total do quickSort: %f\n", total);
	printf("o numero de comparações é de: %d\n", numComp);
	printf("\n");
	
	free(vetor);

	return 0;
}
