#include <stdio.h>
extern int func(int a);
int main() {
  int num = 5;
  num = func(num);
  printf("number is %d\n", num);
  return num;
}
