/*
  https://codeforces.com/problemset/problem/529/B
  kaicheng
  2025-06-02
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define PII pair<int, int>

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &p : a) {
    cin >> p.first >> p.second; // w, h
  }

  int ans = LLONG_MAX;
  for (int i = 1; i <= 1000; ++i) {
    int cnt = 0, sum = 0;
    vector<int> dif;

    for (auto &[w, h] : a) {
      if (w > i && h > i) {
        cnt = n + 1;
        break;
      }
      if (h > i) {
        sum += h;
        cnt++;
      } else {
        sum += w;
        if (w <= i) {
          dif.push_back(w - h);
        }
      }
    }

    if (cnt <= n / 2) {
      sort(dif.rbegin(), dif.rend());
      int t = 0;
      while (t < dif.size() && cnt + t + 1 <= n / 2 && dif[t] > 0) {
        sum -= dif[t];
        t++;
      }
      ans = min(ans, sum * i);
    }
  }

  cout << ans << '\n';
  return 0;
}