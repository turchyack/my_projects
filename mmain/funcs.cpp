
#include <cstdio>
#include <cstdint>


void func1(int a[], int size){
printf("нормально нормально\n");
for(int i = 0; i < size; ++i) {
a[i] = i * i - 1;
printf("a[i]=%i\n", a[i]);
}

}
