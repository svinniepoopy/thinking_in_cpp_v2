/*
 *  Test the speed of your computer. Call srand(time(0)), then make an array of
 *  random numbers. Call srand(time(0)) again and generate the same number of
 *  random numbers in a second array. Use equal( ) to see if the arrays are the
 *  same. (If your computer is fast enough, time(0) will return the same value
 *  both times it is called.) If the arrays are not the same, sort them and use
 *  mismatch( ) to see where they differ. If they are the same, increase the
 *  length of your array and try again.
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>

int N = 10000000;

void SpeedTest() {
  srand(time(0));
  int A[N];
  for (int i=0;i<N;++i) {
    A[i] = rand();
  }
  srand(time(0));
  int B[N];
  for (int i=0;i<N;++i) {
    B[i] = rand();
  }
  bool eq = std::equal(A, A+N, B, B+N);
  if (!eq) {
    std::sort(A, A+N);
    std::sort(B, B+N);
    auto p = std::mismatch(A, A+N, B);
    std::cout << "Times differ at: " << std::distance(A, p.first) 
      << " & " << std::distance(B, p.second) << '\n';
  } else {
    std::cout << "Arrays are equal\n";
  }
}

int main() {
  SpeedTest();
  return 0;
}
