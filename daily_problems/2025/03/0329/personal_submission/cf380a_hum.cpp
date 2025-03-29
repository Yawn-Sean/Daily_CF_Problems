#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> sum;
  vector<int> a;
  sum.push_back(0);
  int M = 1e5;
  vector<array<int, 2>> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i][0];
    if (t[i][0] == 1) {
      cin >> t[i][1];
      sum.push_back(sum.back() + 1);
      if (a.size() < M) {
        a.push_back(t[i][1]);
      }
    } else {
      long long c;
      cin >> t[i][1] >> c;
      sum.push_back(sum.back() + c * t[i][1]);
      for (int j = 0; j < c; ++j) {
        for (int k = 0; k < t[i][1]; ++k) {
          a.push_back(a[k]);
          if (a.size() > M) {
            goto skip;
          }
        }
      }
    skip:;
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    long long x;
    cin >> x;
    int p = ranges::lower_bound(sum, x) - sum.begin() - 1;
    if (t[p][0] == 1) {
      cout << t[p][1] << " ";
    } else {
      cout << a[(x - sum[p] - 1) % t[p][1]] << " ";
    }
  }
}

