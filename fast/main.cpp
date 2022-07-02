#include <cstddef>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "qsort.h"



//using namespace std;


int main(){

  int a[100];
  int* adr = &a[0];
  size_t SIZE = sizeof(a)/sizeof(a[1]);

  printf("\nразмер массива = %lu\n", SIZE);

  for (size_t i = 0; i < SIZE; ++i) {
    a[i] = rand() % 1000;

    }

  printf("---------Не сортированный массив----------\n");


  for (size_t i = 0; i < SIZE; ++i){
    printf("№%lu:%i\n",i, a[i]);
    }

  qsortRecursive(adr,SIZE);


  printf("---------Сортированный массив----------\n");


  for (size_t i = 0; i < SIZE; ++i){

    printf("№%lu = %i\n",i, a[i]);

    }



}