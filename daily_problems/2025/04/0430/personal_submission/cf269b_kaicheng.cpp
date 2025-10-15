#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n, m;
  cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    double x;
    cin >> a[i] >> x;
  }
  vector<int> lis;
  for(auto &x:a){
    auto it = upper_bound(lis.begin(), lis.end(), x);
    if(it == lis.end()){
      lis.push_back(x);
    }else{
      *it = x;
    }
  }
  cout << n - lis.size() << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}