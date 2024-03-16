#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, x[N], y[N];

void _main(){
  cin >> n;
  map<pii, int> cnt;
  for(int i=1; i<=n; ++i){
    cin >> x[i] >> y[i];
    for(int j=1; j<i; ++j){
      ++cnt[mp(x[i]+x[j], y[i]+y[j])];
    }
  }
  ll ans = 0;
  for(auto [p, c] : cnt){
    ans += 1ll * c * (c - 1) / 2;
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
