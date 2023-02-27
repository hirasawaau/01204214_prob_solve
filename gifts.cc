#include<iostream>
#include<vector>

using namespace std;

int main() {
  vector<int> v;
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  int s = 0;
  for (int i = 0; i < n; i++) {
    if(v[i] >=0){
      s += v[i];
    }
  }

  cout << s << endl;
  return 0;
}
