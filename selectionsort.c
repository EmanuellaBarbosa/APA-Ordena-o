// Selection Sort

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

	selection_sort(num, size);
	FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		fprintf(file, "%d\n", num[i]);
	}



}
