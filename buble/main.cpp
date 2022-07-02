#include <cstddef>
#include <cstdio>
#include <iostream>


using namespace std;

int main(){




int a[] = {3, 7, 19, 22, 56, 5, 1};

size_t SIZE = sizeof(a)/sizeof(a[1]);

printf("пиво\nразмер массива = %lu\n", SIZE);

for (size_t i = 0; i < SIZE; i++){

  printf("№%lu:%i\n",i, a[i]);
    }


    for (size_t i = 0; i < SIZE; i++){

      for (size_t j = 0; j < SIZE - 1 - i; j++){

        if(a[j] > a[j+1]){

          swap(a[j], a[j+1]);

        }

      }











    }



for (size_t i = 0; i < SIZE; ++i){

  printf("№%lu:%i\n",i, a[i]);
    }





}