#include <bits/stdc++.h>

using namespace std;

int main() {
  list<int> l;
  int n;

  cin >> n;
  int x;
  int buf;

  for (int i = 0; i < n; i++) {
    string command;
    cin >> command;

    if (command == "ri") {
      cin >> x;
      l.push_back(x);
    } else if (command == "li") {
      int x;
      cin >> x;
      l.push_front(x);
    } else if (command == "rr") {
      l.push_front(*(--l.end()));
      l.pop_back();
    } else if (command == "lr") {
      l.push_back(*l.begin());
      l.pop_front();
    }
  }

  int lSize = l.size();

  for (int i = 0; i < lSize; i++) {
    buf = *l.begin();
    cout << buf << "\n";
    l.pop_front();
  }
}