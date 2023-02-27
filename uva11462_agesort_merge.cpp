#include <iostream>
#include <vector>
using namespace std;

// merge sort
void merge(vector<int>& a, int l, int m, int r, int& count) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++) {
    L[i] = a[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = a[m + 1 + j];
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
      count += n1 - i;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int>& a, int l, int r, int& count) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(a, l, m, count);
    mergeSort(a, m + 1, r, count);
    merge(a, l, m, r, count);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> a;
  int n;
  while (cin >> n && n) {
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int count = 0;

    mergeSort(a, 0, n - 1, count);

    for (int i = 0; i < n - 1; i++) {
      cout << a[i] << " ";
    }

    cout << a[n - 1] << "\n";
  }
}