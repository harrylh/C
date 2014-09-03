/*large root pile   2014/9/3 */

#include <stdio.h>
#include <stdlib.h>
typedef int valType;

/* adjust heap from i node in a[] whose length is length*/
int MinHeapFixDown(valType a[], int i, int length) {
   int j = 2 * i + 1;
   valType temp;

   if ( i < 0 || length < 0) {
      printf("invalid parameter \n");
      return -1;
   }

   temp = a[i];

   while (j < length) {
      if (j + 1 < length && a[j] < a[j + 1]) {
         j++;
      }

      if (a[j] < temp) {
         break;
      }

      a[i] = a[j];
      i = j;
      j = 2 * i + 1;
   }

   a[i] = temp;
   return 0;
}
/* buid a heap */
int buildHeap(valType a[], int n) {

   int i = 0;

   for (i = n / 2 - 1; i >= 0; i--) {
      MinHeapFixDown(a, i, n);
   }
   return 0;
}

int HeapSort(valType a[], int n) {

   int i = 0;
   valType temp;

   for (i = n - 1; i > 0; i--) {
      temp = a[0];
      a[0] = a[i];
      a[i] = temp;

      MinHeapFixDown(a, 0, i);
   }
   return 0;
}
/* insert a node from the bottom of a[] (a[n]) and adjust the heap */
int MinHeapFixup(valType a[], int n) {

   int i = 0;
   valType temp = a[n];


   i = (n-1)/2;

   while (i >= 0 && n != 0) {
      if (a[i] > temp) {
         break;
      }
      a[n] = a[i];
      n = i;
      i = (n-1)/2;
   }

   a[n] = temp;
   return 0;

/*   for (i = (n-1)/2; i >=0 && n !=0 && a[i] > a[j]; n = i, i = (n-1)/2){
      a[n] = a[i];
   }*/

}

int main(int argc, char ** argv) {

   int a[9] = { 0 };
   int i = 0;

   for (i = 0; i < sizeof(a) / sizeof(int); i++) {
      a[i] = i;
   }


   printf("initial a[0-8] : \n");
   for (i = 0; i < sizeof(a) / sizeof(int); i++) {
      printf(" %d ", a[i]);
   }
   printf("\n");

   if (buildHeap(a, 8)) {
      printf("error \n");
      return -1;
   }

   printf("after build heap a[0-7] : \n");
   for (i = 0; i < sizeof(a) / sizeof(int); i++) {
      printf(" %d ", a[i]);
   }
   printf("\n");


   MinHeapFixup(a, 8);
   printf("after heap insert a[8]: \n");
   for (i = 0; i < sizeof(a) / sizeof(int); i++) {
      printf(" %d ", a[i]);
   }
   printf("\n");
   
   HeapSort(a, 9);

   printf("after heap sort a[0-8]: \n");
   for (i = 0; i < sizeof(a) / sizeof(int); i++) {
      printf(" %d ", a[i]);
   }
   printf("\n");


   return 0;
}