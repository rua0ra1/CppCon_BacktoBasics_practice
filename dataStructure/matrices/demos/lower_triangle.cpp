#include <iostream>

using namespace std;

class LowerTriangular {
private:
  int *A;
  int n;

public:
  LowerTriangular() // Default constructor
  {
    n = 2;
    A = new int[2 * (2 + 1) / 2];
  }

  LowerTriangular(int n) {
    this->n = n;
    A = new int[n * (n + 1) / 2];
  }

  ~LowerTriangular() { delete[] A; }

  void set(int i, int j, int x);

  int get(int i, int j);

  void display();
};

void LowerTriangular::set(int i, int j, int x) {
  if (i >= j)
    A[i * (i + 1) / 2 + j] = x;
}
int LowerTriangular::get(int i, int j) {
  if (i >= j)
    return A[i * (i + 1) / 2 + j];
  else
    return 0;
}
void LowerTriangular::display() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= j)
        cout << A[i * (i + 1) / 2 + j] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}
int main() {
  LowerTriangular m(5);
  m.set(0, 0, 5);
  m.set(1, 0, 6);
  m.set(1, 1, 7);
  m.set(2, 0, 8);
  m.set(2, 1, 9);
  m.set(2, 2, 10);
  m.set(3, 0, 11);
  m.set(3, 1, 12);
  m.set(3, 2, 13);
  m.set(3, 3, 14);
  m.set(4, 0, 15);
  m.set(4, 1, 16);
  m.set(4, 2, 17);
  m.set(4, 3, 18);
  m.set(4, 4, 19);
  m.display();
  cout << m.get(3, 3) << endl;
  cout << m.get(2, 3) << endl;
  cout << m.get(4, 2) << endl;
}      