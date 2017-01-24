//Heapsort

#include <stdio.h>
#include <stdlib.h>
 
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

  heapsort(num, size);
  FILE* file = fopen(argv[1], "w");
  for(i = 0; i<size; i++){
    printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
    fprintf(file, "%d\n", num[i]);
  }

}