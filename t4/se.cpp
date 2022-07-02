#include <cstdio>
#include <string>

static int z = 5;


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

static BlockTracer tt2("tt2", __FILE__, __LINE__);

int get_z() {
  return z;
}

int se(){
  extern int b;
  printf("b #1 = %d\n", b);
  return 0;
}