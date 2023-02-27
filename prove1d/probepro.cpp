
#include "probelib.h"

void check(int a, int b) {
  if (a == b) {
    // std::cout << a << "\n";
    probe_answer(a);
  }

  //   std::cout << a << " " << b << std::endl;

  if (probe_check(a, (a + b) / 2)) {
    check(a, (a + b) / 2);
  } else {
    check(((a + b) / 2) + 1, b);
  }
}

int main(void) {
  int n = probe_init();
  check(0, n - 1);
}