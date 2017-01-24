// Mergesort

#include <stdio.h>
#include <stdlib.h>

void mergesort (int num[], int posicaoInicial, int posicaoFinal){
	int i, j, k, halfsize, *aux;

 if(posicaoInicial == posicaoFinal) return;
 
    halfsize = (posicaoInicial + posicaoFinal) / 2;
    mergesort(num, posicaoInicial, halfsize);
    mergesort(num, halfsize + 1, posicaoFinal);
 
    i = posicaoInicial;
    j = halfsize + 1;
    k = 0;
    aux= (int *) malloc(sizeof(int) * (posicaoFinal - posicaoInicial + 1));
 
    while(i < halfsize + 1 || j  < posicaoFinal + 1) {
        if (i == halfsize + 1 ) { 
            aux[k] = num[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFinal + 1) { 
                aux[k] = num[i];
                i++;
                k++;
            }
            else {
                if (num[i] < num[j]) {
                    aux[k] = num[i];
                    i++;
                    k++;
                }
                else {
                    aux[k] = num[j];
                    j++;
                    k++;
                }
            }
        }
 
    }
 
    for(i = posicaoInicial; i <= posicaoFinal; i++) {
        num[i] = aux[i - posicaoInicial];
    }
    free(aux);
 
}
 
int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

	mergesort(num, 0,size-1);
	FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		fprintf(file, "%d\n", num[i]);
	}

}



