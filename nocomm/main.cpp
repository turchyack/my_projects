/*
  Мои эксперементы со структурами
*/

#include <cstdio>
#include <cstdint>
#include <iostream>
#include "funcs.h"
#include "printpic.h"

using namespace std;
struct Structure1
  {
    char c;
    int i;
    float f;
    double d;

    };

typedef struct
  {
    char c;
    int i;
    float f;
    double d;
  } Structure2;

typedef struct Structure3
  {
    char c;
    int i;
    float f;
    double d;
  } Structure3;

typedef struct SelfReferental
  {
    int i;
    SelfReferental* sr;
  } SelfReferental;

enum ShapeType
  {
    circle,
    square,
    rectangle
  };
  typedef struct {
    int i, j, k;
  } ThreeDpoint;










int main() {

  int x;
  cin >> x;
  printpic(x);
  if(x==1) {
      struct Structure1 s1, s2;
      s1.c = 'a';
      s1.i = 1;
      s1.f = 3.14;
      s1.d = 0.000009;
      s2.c = 'a';
      s2.i = 1;
      s2.f = 3.14;
      s2.d = 0.000009;

      printf("%c\nпроверка\n", s1.c);
      printf("%i\nпроверка\n", s1.i);
      printf("%f\nпроверка\n", s2.d);
      printf("%f\nпроверка\n", s2.f);

      SelfReferental sr1, sr2;
      sr1.sr = &sr2;
      sr2.sr = &sr1;
      sr1.i=55;
      sr2.i = 999;
      printf("%p\nпроверка\n", sr1.sr);
      printf("%p\nпроверка\n", sr2.sr);

      Structure3 st1, st2;
      Structure3* sp = &st1;
      sp -> c = 'p';
      sp -> i = 54211;
      sp -> f = 3.14;
      sp -> d = 0.0009;
      sp = &st2;
      sp -> c = 'f';
      sp -> i = 45423;
      sp -> f = 5342.1231;
      sp -> d = 0.656;
      printf("%c\nпроверка\n", st1.c);
      printf("%i\nпроверка\n", st1.i);
      printf("%f\nпроверка\n", st2.d);
      printf("%f\nпроверка\n", st2.f);
      ShapeType shape = circle;
        switch(shape) {
          case circle: printf("circle\n"); break;
          case square: printf("square\n");break;
          case rectangle: printf("rectangle\n");break;
          }

      ThreeDpoint p[10];
        for(int i = 0; i<10; ++i) {
        printf("p[i].i=%i\n",p[i].i);
        p[i].i = i + 1;
        printf("&p[i].k=%p\n",&p[i].k);
        printf("p[i].i=%i\n",p[i].i);
        printf("p[i].j=%i\n",p[i].j);
        p[i].j = i + 2;
        printf("p[i].j=%i\n",p[i].j);
        p[i].k = i + 3;
        printf("p[i].k=%i\n",p[i].k);
        }
      }
  else {
    int a[] = {212,123,228,1488,1337,23,43,58,22,99};
    printf("a=%p\n", a);
    printf("&a[0]=%p\n", &a[0]);
    printf("a[0]=%i\n", a[1]);
    func1(a, 4);






















}














}


