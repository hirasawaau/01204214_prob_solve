#include <iostream>
#include <vector>
#define MAX_VALUE 100000

using namespace std;

vector<int> A;
vector<int> MEM(MAX_VALUE, -1);

int find(int n) {
  if (n >= A.size()) {
    return 0;
  }
  if (n <= 0) {
    return A[n];
  }
  if (MEM[n - 1] != -1) {
    return 1 + MEM[n - 1];
  }
  int max_value = 0;
  for (int i = 0; i < n - 1; i++) {
    if (A[i] < A[n] && A[i] > max_value) {
      max_value = A[i];
    }
  }

  MEM[n - 1] = max_value;
  return 1 + max_value;
}

int main() {
  /*
  x[i] = 1 + max(x[i-1 ...0]) // x[i] means length of sequence ending at i
  */

  int n;
  cin >> n;
  A.resize(n);
  MEM.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
  }
}