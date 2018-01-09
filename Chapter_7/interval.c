void donothing(int a) { return; }

int func(int i) {
  int a = 5;
  donothing(a);
  int m = a;
  donothing(m);
  a = 9;
  if (i < 5) {
    int b = 3;
    donothing(b);
    int z = b;
    donothing(z);
  } else {
    int k = a;
    donothing(k);
  }

  return m;
}
