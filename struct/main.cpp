  /*
  Типы данных: Струуктуры
*/

#include <cstdio>
#include <cstdint>

#include "utils.h"

struct S {};

struct S0 {
  S0() {
    printf("constructor S0, this=%p\n", this);
  }
  S0(int x) {
    printf("constructor S0(%d), this=%p\n", x, this);
  }
  ~S0() {
    printf("destructor S0, this=%p\n", this);
  }
};

struct S1 {
  char a;
};

struct S2 {
  int a;
  char b;
  char c;
};

struct S3 {
  int a;
  int b;
  int c;
};

struct S4 {
  char a;
  char b;
  char c;
};

struct D0 {
  D0(int d) : d(d) {}
  int get_d() const { // int get_d(const D0* this);
    // this->d += 1;
    return d; // this->d;
  }

private:
  D0();

  int d;
};

struct S5 {
  S5(char a, int offset) : a(a+offset), d(offset) {
    //this->a = a + offset;
    //d.d = offset;
  }
  S5(char a) : a(a), d(0) {

  }
  char a;
  D0 d;
};

int main() {
  {
    printf("pass #1\n");
    S0 a; // = S0();
    S0 b = S0();
    S0 c = S0(3);
    S0 d(4);
    printf("pass #2\n");

    printf("sizeof(a)=%zd\n", sizeof(a));
    print_hexdump("a: ", &a, sizeof(a));
    print_hexdump("b: ", &b, sizeof(b));
    print_hexdump("c: ", &c, sizeof(c));
    print_hexdump("d: ", &d, sizeof(d));
    printf("end of block #3\n");
  }

  {
    S1 s1 = {
      'J'
    };

    printf("sizeof(s1)=%zd\n", sizeof(s1));
    print_hexdump("s1: ", &s1, sizeof(s1));

    S1 s1_0 = {
      .a = 'M'
    };
    printf("s1_0.a = '%c'\n", s1_0.a);

    S1 m1[2];

    printf("sizeof(m1)=%zd\n", sizeof(m1));
    print_hexdump("m1: ", m1, sizeof(m1));
  }

  {
    S2 s2 = {'J', 3, 'M'};
    print_hexdump("s2: ", &s2, sizeof(s2));

    S3 s3;
    print_hexdump("s3: ", &s3, sizeof(s3));

    S4 s4;
    print_hexdump("s4: ", &s4, sizeof(s4));
  }

  {
    S2 s = { 1, 'J', 'M'};
    print_hexdump("s: ", &s, sizeof(s));
    S2 const* p = &s;

    printf("s.a = %d, %d, %d, %d, %p\n",
      s.a, p->a, (*p).a, (&s)->a,
      &(p->a)
    );
    printf("s.b = %c, %c, %c, %c, %p\n",
      s.b, p->b, (*p).b, (&s)->b,
       &(p->b)
    );
    printf("s.c = %c, %c, %c, %c, %p\n",
      s.c, p->c, (*p).c, (&s)->c,
      &(p->c)
    );
  }

  {
    S5 a('J', 3);
    printf("a.a = '%c', a.d.d = %d\n", a.a, a.d.get_d());
  }

	return 0;
}
