#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, a[N];
ll f[2], g[2];

void _main(){
  cin >> n;
  for(int i=1; i<=n; ++i) cin >> a[i];
  ll ans = 0;
  f[0] = f[1] = 0;
  for(int i=2; i<=n; ++i){
    ll d = abs(a[i] - a[i-1]);
    g[0] = max(0ll, f[1] - d);
    g[1] = max(d, f[0] + d);
    ans = max(ans, max(g[0], g[1]));
    swap(f, g);
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}