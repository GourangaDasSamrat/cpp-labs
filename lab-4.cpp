// data modifier

#include <iostream>
using namespace std;

int main() {
  // unsigned
  // unsigned means signed elements not allowed, like -100
  unsigned int smallTeaPack = -100;
  /* we use unsigned here but give a signed value, so if we print it it show
   another value, that is garbage value
  */

  // long typed data
  // long is for save long data, its number typed data, its big bother of int ,
  // also
  long LargeTeaStall = 574857857485724;
  /*
  if we use int here its throw an error, but if we use double its show
  :5.74858e+14,same in float.
  */

  // long long
  // if we need more long, then we use long long
  long long extraLargeStall = 4347284782478888887;

  // short typed data
  short teaSample = 100;

  cout << extraLargeStall << endl;
  return 0;
}
