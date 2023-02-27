#include <iostream>
#include <vector>

#define MAX_VALUE 100000

using namespace std;

int a[MAX_VALUE];

vector<int> mem_max(MAX_VALUE, -1);

int N;

/*
A[i] = max(A[i+1] , A[i+3] + arr[i+2])
*/
int find_max(int n) {
  if (n + 1 > N || n + 3 > N) {
    return 0;
  }
  if (mem_max[n] != -1) {
    return mem_max[n];
  }
  int max_value = max(find_max(n + 1), find_max(n + 3) + a[n + 2]);
  mem_max[n] = max_value;
  return max_value;
}

int main(void) {
  /*
  A[i] = P[i] + max(A[1...(i-3)])
  */

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int ans = find_max(0);

  cout << ans;
}