#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long

string res;

bool check(const string &pref, const string &suf, const vector<string> &v,
           int n) {
  string s = pref + suf.substr(n - 2);
  multiset<string> vv, pre, suff;
  for (int i = 0; i < n - 1; ++i) {
    pre.insert(s.substr(0, n - i - 1));
    vv.insert(s.substr(0, n - i - 1));
    suff.insert(s.substr(i + 1));
    vv.insert(s.substr(i + 1));
  }
  if (vv == multiset<string>(v.begin(), v.end())) {
    for (int i = 0; i < 2 * n - 2; ++i) {
      if (pre.count(v[i])) {
        res += 'P';
        pre.erase(pre.find(v[i]));
      } else if (suff.count(v[i])) {
        res += 'S';
        suff.erase(suff.find(v[i]));
      } else {
        assert(false);
      }
    }
    return true;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<string> v(2 * n - 2);
  vector<string> a;
  for (int i = 0; i < 2 * n - 2; ++i) {
    cin >> v[i];
    if ((int)(v[i].size()) == n - 1) {
      a.push_back(v[i]);
    }
  }

  if (check(a[0], a[1], v, n)) {
    cout << res << endl;
  } else {
    res.clear();
    check(a[1], a[0], v, n);
    cout << res << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}