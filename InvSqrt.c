#include <stdio.h>
#define MAGIC_NUM 0x5f375a86
#define MAGIC_NUM2 0x5f3759df

float InvSqrt(float x) {
   float xhalf = 0.5f * x;
   int i = *(int*)&x;
   
   i = MAGIC_NUM - (i>>1);
   x = *(float*)&i;
   x = x*(1.5f - xhalf*x*x);
   x = x*(1.5f - xhalf*x*x);
   return x;
}

int main() {
   float f = 8.0;
   printf("InvSqrt: %f\n",InvSqrt(f));
   return 0;
}