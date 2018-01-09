#include <stdio.h>
int globalvar = 0;

int func2(int a, int b) {
  globalvar++;
  return a * b;
}

int func1(int a, int b) {
  globalvar++;
  int d = a + b;
  int e = a - b;
  int f = func2(d, e);
  return f;
}

int main() {
  globalvar++;
  int a = 5;
  int b = 3;

  int c = func1(a, b);
  printf("%d", c);
  return c;
}
