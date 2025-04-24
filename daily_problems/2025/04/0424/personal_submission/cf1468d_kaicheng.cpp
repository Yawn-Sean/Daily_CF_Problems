#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long

void solve() {
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  std::vector<int> s(m);
  for(auto &x:s){
    cin>>x;
  }
  sort(s.begin(),s.end());
  int max_len = (a<b ? b-1:n-b);
  int num=min(m,abs(a-b)-1);
  int ans = 0;
  for(int i=num-1;i>=0;i--){
    if(s[i]<max_len){
      max_len--;
      ans++;
    }
  }
  cout<<ans<<'\n';

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
