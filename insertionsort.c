// Isertionsort

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

int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

	insertion_sort(num, size);
	FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		fprintf(file, "%d\n", num[i]);
	}

}


