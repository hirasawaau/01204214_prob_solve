#include <iostream>
#include <string>

using namespace std;

string input;
string seq;

int main() {
  cin >> input;
  cin >> seq;

  char iter = input[0];
  const char last = input[input.length() - 1];
  int count = 0;
  int word = 0;
  for (int i = 0; i < seq.length(); i++) {
    if (seq[i] == iter) {
      iter = input[++count];
    }

    if (count == input.length()) {
      count = 0;
      word++;
      iter = input[0];
    }
  }

  cout << word;
  return 0;
}