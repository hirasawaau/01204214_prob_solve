#include <iostream>
#include <utility>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  pair<int, int> c[4] = {make_pair(0, 0), make_pair(0, 0), make_pair(0, 0),
                         make_pair(0, 0)};

  int currentLine = 0;

  for (int i = 1; i <= 4 * N; i++) {
    int score;
    cin >> score;
    if (score > c[currentLine].second) {
      c[currentLine].first = i;
      c[currentLine].second = score;
    }
    if (i % N == 0) {
      currentLine++;
    }
  }

  pair<int, int> A;
  pair<int, int> lA;
  pair<int, int> B;
  pair<int, int> lB;
  if (c[0].second > c[1].second) {
    A = c[0];
    lA = c[1];
  } else {
    A = c[1];
    lA = c[0];
  }

  if (c[2].second > c[3].second) {
    B = c[2];
    lB = c[3];
  } else {
    B = c[3];
    lB = c[2];
  }

  if (A.second > B.second) {
    cout << A.first << " " << B.first << " ";
  } else {
    cout << B.first << " " << A.first << " ";
  }

  cout << lA.first << " " << lB.first << "\n";

  return 0;
}