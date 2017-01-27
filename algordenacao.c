
#include <stdio.h>
#include <stdlib.h>

void insertion_sort (int num[], int size)
{

	int i, j, aux;
	for (i = 1; i < size; i++){
		aux = num[i];
		for(j = i; (j > 0) && (aux < num[j-1]); j--){
			num[j] = num[j-1];
		}
		num[j] = aux;
	}
}


void selection_sort (int num[], int size)
{

	int i,j, var_temp, menor;

	for (i=0; i<size; i++){
		menor = i;
	for(j = i + 1; j<size; j++){
		if (num[menor] > num [j])
			menor = j;
		}

		if (i!= menor){
			var_temp = num[i];
			num[i] = num[menor];
			num[menor] =var_temp;
		}

	}

}



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



void quick_sort(int num[], int initial, int end){
    int i = initial, j = end, pivo, aux;
    pivo = num[(initial + end)/2];
    while(i<j){
        while(num[i] < pivo) i++;
        while(num[j] > pivo) j--;
        if(i <= j){
            aux = num[i];
            num[i++] = num[j];
            num[j--] = aux;
        }
    }
    if(j > initial) quick_sort(num, initial, j);
    if(i < end) quick_sort(num, i, end);

    return;
}




void heapsort(int num[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = num[i];
      } else {
          n--;
          if (n == 0) return;
          t = num[n];
          num[n] = num[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (num[filho + 1] > num[filho]))
              filho++;
          if (num[filho] > t) {
             num[pai] = num[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      num[pai] = t;
   }
}


int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

        switch(*argv[1])
    {
        case '1':
            insertion_sort(num, size);
            break;
       case '2':
            selection_sort(num, size);
            break;
       case '3':
            mergesort(num, 0,size-1);
            break;
       case '4':
           quick_sort(num, 0,size-1);
            break;
       case '5':
             heapsort(num, size);
            break;
    }


	//FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		//printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		printf( "%d\n", num[i]);
	}

}













