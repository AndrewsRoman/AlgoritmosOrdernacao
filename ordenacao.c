#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// FUNCAO BUSCA SEQUENCIAL //
int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes){
	int inicio = 0;
	if (inicio > tam)
		return -1;
		
	*numComparacoes=*numComparacoes+1;
	if (valor == vetor[tam]){
		return tam;
	}
	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

// FUNCAO BUSCA BINARIA // 
int buscaBinaria2(int vetor[], int valor, int* numComparacoes, int inicio, int final){
	int i;
	i = (inicio + final)/2;
	if (inicio > final)
		return -1;
	*numComparacoes=*numComparacoes+1;	
	if (valor == vetor[i])
		return i;
	*numComparacoes=*numComparacoes+1;
	if (valor > vetor[i])		
		return buscaBinaria2(vetor, valor, numComparacoes, i+1, final);
	else
		return buscaBinaria2(vetor, valor, numComparacoes, inicio, i-1);
}
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	return buscaBinaria2 (vetor, valor, numComparacoes, 0, tam-1);
}


// FUNCAO TROCA //
void troca(int vetor[], int a, int b) {

	int aux = vetor[a];
	vetor[a] = vetor[b];
  	vetor[b] = aux;
}

// FUNCAO INSERTION SORT //
int insertionSort2(int vetor[], int tam, int* numComp){
	int i, aux;
	if (tam > 0){
		
		insertionSort2(vetor, tam-1, numComp);
		aux = vetor[tam];	
		i = tam-1;
		numComp = numComp + 1;
		while ( (aux < vetor[i]) && (i >= 0) ){
			numComp = numComp + 1;
			vetor[i+1] = vetor[i];
			i--;
			vetor[i+1] = aux;
			numComp = numComp + 1;
		}
	}
	return numComp;	
	
}
int insertionSort(int vetor[], int tam){
	int numcomp=0;
	return insertionSort2(vetor,tam,numcomp);
}
// FUNÇÃO QUE ENCONTRA O MENOR ELEMENTO //
int menor_elemento(int vetor[], int inicio, int final, int *numcomp){
	int menor = inicio;
	for (int i=inicio; i<final; i++){
		*numcomp= *numcomp+1;
		if (vetor[i] < vetor[menor])
			menor = i;
	}
	return menor;
}
// FUNÇÃO SELECTION SORT// 
int selectionSort2( int vetor[], int inicio, int fim, int *numcomp){
	if (fim < inicio){
		return 0;
	}
	troca(vetor, inicio, menor_elemento(vetor,inicio,fim, &numcomp));
	selectionSort2(vetor, inicio+1, fim, numcomp);
	return numcomp;
}
int selectionSort(int vetor[], int tam){
	int numcomp=0;
	return numcomp + selectionSort2(vetor, 0, tam, numcomp);
	
}



//FUNÇÃO MESCLA//
int mescla(int vetor[], int a, int m, int b, int* numcomp){
	if (a >= b)
		return 0;
	int *vetortemp;
	int i,j,tam, indice1,indice2,k;
	int fim1 =0;
	int fim2 =0;
	tam = b-a+1;
	//alocando memoria para o vetor auxiliar/temporario
	vetortemp = (int *) malloc(tam*sizeof(int));
	indice1=a;
	indice2=m+1;
	//percorrendo o vetor temporario
	for (i = 0; i < tam; i++){
		// se um dos vetores for 1 significa q acabou e q é so copiar o outro para o vetor temp
		if (!fim1 && !fim2){
			//verifica qual o menor elemento e o coloca no vetor temporario
			*numcomp=*numcomp+1;
			if (vetor[indice1] < vetor[indice2]){
				vetortemp[i] = vetor[indice1];
				indice1++;
			}
			else {
				vetortemp[i] = vetor[indice2];
				indice2++;
			}
			// verifica se o indice 1 é maior que o meio, se sim significa q ele passou do limite
			if (indice1 > m)
				fim1=1;
			if (indice2 > b)
				fim2=1;
		}
		//acontece se um dos vetores tiver acabado e copia as posições que sobraram para o vetor temp
		else{
			if (!fim1){
				vetortemp[i] = vetor[indice1];
				indice1++;
			}
			else{
				vetortemp[i] = vetor[indice2];
				indice2++;
			}
		}		
	}
	//atribuindo os valores do vetortemp para o vetor
	for(j=0, k=a; j<tam; j++, k++){
		vetor[k] = vetortemp[j];
	}
	free(vetortemp);
	return *numcomp;
	
}

//FUNÇÃO MERGE SORT //
int mergeSort2(int vetor[], int inicio, int final, int *numcomp){
	if (inicio >= final)
		return 0;
	int meio;
	meio=((inicio+final)/2);
	
	mergeSort2(vetor, inicio, meio, numcomp);
	
	mergeSort2(vetor, meio+1, final, numcomp);
	return numcomp + mescla(vetor, inicio, meio, final, &numcomp);
	
	
}

int mergeSort(int vetor[], int tam){
	int numcomp;
	numcomp=0;
	return mergeSort2(vetor, 0, tam-1, numcomp);
}



int particiona(int vetor[], int a, int b, int* numcomp) {	  
	int i, j;
	i=a;
	j=b;

	while(i<j){	
		while(vetor[i]<=vetor[a]){			
			i++;
			*numcomp=*numcomp+1;
		}
		while(vetor[j] >vetor[a]){
			j--;
			*numcomp=*numcomp+1;
		}
		if (i < j)
			troca(vetor,i,j);
	}
	troca(vetor,j,a);
	return j;
	
}                                                                   
// FUNCAO QUICKSORT //
int quickSort2(int vetor[], int inicio, int final, int* numcomp){	
	if (inicio < final){
		int m = particiona(vetor,inicio,final, numcomp);
		quickSort2(vetor,inicio,m-1, numcomp);
		quickSort2(vetor,m+1,final, numcomp);
		return *numcomp;
	}
	return 0;
}
int quickSort(int vetor[], int tam){
	int numcomp;
	numcomp=0;
	return quickSort2(vetor, 0, tam-1, &numcomp);
}



