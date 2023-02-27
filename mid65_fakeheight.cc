#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

typedef long long int lli;

using namespace std;

int main() {
  vector<lli> deks;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    lli k;
    cin >> k;
    deks.push_back(k);
  }

  vector<pair<int, lli> > d;
  lli maxDiff = LLONG_MIN;
  lli sum = 0;
  for (int i = 1; i < n; i++) {
    lli v = abs(deks[i] - deks[i - 1]);
    sum += v;
    d.push_back(make_pair(i - 1, v));
    if (v > maxDiff) {
      maxDiff = v;
    }
  }

  vector<lli> diffs;

  for (auto i : d) {
    if (maxDiff != i.second) {
      continue;
    }
    vector<lli> tr = deks;

    int candidateIndex = i.first;
    lli value = i.second;
    auto canditate_iter = tr.begin() + i.first;

    lli diffValue = LLONG_MIN;

    vector<lli>::iterator valueChange;

    for (auto i = tr.begin(); i != tr.end(); i++) {
      if (i == canditate_iter || i == canditate_iter - 1 ||
          i == canditate_iter + 1) {
        continue;
      }

      lli k = abs(*canditate_iter - *i);
      //   cout << k << "\n";

      if (k > diffValue) {
        diffValue = k;
        valueChange = i;
      }
    }

    tr[candidateIndex] = *valueChange;
    // for (auto i : tr) {
    //   cout << i << " ";
    // }
    // cout << "\n";
    lli sum = 0;
    for (int i = 1; i < n; i++) {
      sum += abs(tr[i] - tr[i - 1]);
    }

    diffs.push_back(sum);
  }
  lli min = LLONG_MAX;
  for (auto i : diffs) {
    if (i < min) {
      min = i;
    }
  }

  cout << min;
}