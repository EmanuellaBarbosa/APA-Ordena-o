//Quicksort

#include <stdio.h>
#include <stdlib.h>

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
 
int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

	quick_sort(num, 0,size-1);
	FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		fprintf(file, "%d\n", num[i]);
	}

}






