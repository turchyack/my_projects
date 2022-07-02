/*
  Переменные. Область видимости. Время жизни.
*/

#include <cstdio>
#include <cstdint>
#include <string>


struct BlockTracer {
  BlockTracer(const char* name, const char* fname, int line) : var_name(name), src_fname(fname), src_line(line) {
    printf("%s (%s[%d]): Create\n", var_name.c_str(), src_fname.c_str(), src_line);
  }

  ~BlockTracer() {
    printf("%s (%s[%d]): Destroy\n", var_name.c_str(), src_fname.c_str(), src_line);
  }

  std::string var_name;
  std::string src_fname;
  int src_line;
};

BlockTracer T1("T1", __FILE__, __LINE__);
static BlockTracer tt1("tt1", __FILE__, __LINE__);



int b = 18;
int se();
static int y=99;

int main() {
  BlockTracer t1("t1", __FILE__, __LINE__);
  BlockTracer t2("t2", __FILE__, __LINE__);

  {
    BlockTracer t3("t3", __FILE__, __LINE__);
    BlockTracer t4("t4", __FILE__, __LINE__);
    {
      BlockTracer t5("t5", __FILE__, __LINE__);
      BlockTracer t6("t6", __FILE__, __LINE__);
      printf("TEST\n");
    }
  }

  y=43;

  printf("b #2 = %d\n", b);
  int b = 5;
  {
    b += 1;
    printf("b = %d\n", b);

    int b = 10;

    printf("b=%d\n", b);

  }
  {
    extern int b;
    printf("b %s[%d] =%d\n", __FILE__, __LINE__, b);
  }
  se();
  printf("b=%d\n", b);

	return 0;
}
