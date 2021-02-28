/*
 * Create a Matrix class template that is made from a vector<vector<T> >.
 * Provide it with a friend ostream& operator<<(ostream&, const Matrix&) to
 * display the matrix. Create the following binary operations using the STL
 * function objects where possible: operator+(const Matrix&, const Matrix&) for
 * matrix addition, operator*(const Matrix&, const vector<int>&) for multiplying
 * a matrix by a vector, and operator*(const Matrix&, const Matrix&) for matrix
 * multiplication. (You might need to look up the mathematical meanings of the
 * matrix operations if you don’t remember them.) Test your Matrix class
 * template using int and float.
 */

#include <iostream>
#include <vector>

namespace {
constexpr int r = 5, c = 5;
}

template<typename T>
class Matrix {
  public:
    Matrix(int r, int c):data(r, std::vector<int>(c)) {}


    // multiply a matrix to another matrix
    Matrix& operator*(const Matrix&) {
    }

    Matrix& operator+(const Matrix&) {
    }

    friend Matrix operator*(const Matrix&, const std::vector<int>&) {
    }

    void operator()(int i, int j) {

    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
      return os;
    }
  private:
    std::vector<std::vector<T>> data;
};

void fill(Matrix<int> & m) {
  for (int i=0;i<r;++i) {
    for (int j=0;j<c;++j) {
      m(i, j) = 1;
    }
  }
}

int main() {
  Matrix<int> m1(r, c);
  Matrix<int> m2(r, c);

  const Matrix& m3 = m1 + m2;
  const Matrix& m4 = m1 * m2;
  std::cout << "addition: \n";
  std::cout << m3;
  std::cout << "multiplication: \n";
  std::cout << m4;

  return 0;
}
