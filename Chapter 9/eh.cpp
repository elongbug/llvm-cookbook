class Ex1 {};
void throw_exception(int a, int b) {
  Ex1 ex1;
  if (a > b) {
    throw ex1;
  }
}

int test_try_catch() {
  try {
    throw_exception(2, 1);
  }
  catch(...) {
    return 1;
  }
  return 0;
}
