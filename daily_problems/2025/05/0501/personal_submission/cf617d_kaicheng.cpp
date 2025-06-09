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
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    
    bool all_x = (x[0]==x[1] && x[1]==x[2]);
    bool all_y = (y[0]==y[1] && y[1]==y[2]);
    
    if (all_x || all_y) {
        cout << "1\n";
        return;
    }
    
    auto check = [&](int i, int j, int k) {
        return ((x[k]==x[i]||x[k]==x[j]) && (y[k]>=min(y[i],y[j]) && y[k]<=max(y[i],y[j]))) ||
               ((y[k]==y[i]||y[k]==y[j]) && (x[k]>=min(x[i],x[j]) && x[k]<=max(x[i],x[j])));
    };
    
    if (check(0,1,2) || check(0,2,1) || check(1,2,0)) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
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