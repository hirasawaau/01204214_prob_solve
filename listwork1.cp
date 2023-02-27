#include <bits/stdc++.h>

#include <list>

using namespace std;

void showList(list<int> l) {
  list<int>::iterator k = l.begin();
  while (k != l.end()) {
    cout << *k << "\n";
    k++;
  }
  //   cout << "\n";
}

int main() {
  list<int> l;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char o;
    int x;
    cin >> o >> x;
    switch (o) {
      case 'I':
        l.push_front(x);
        break;

      case 'D':
        if (x > l.size()) {
          break;
        }
        list<int>::iterator k = l.begin();
        advance(k, x - 1);

        l.erase(k);
        break;
    }
    // showList(l);
  }

  showList(l);
}