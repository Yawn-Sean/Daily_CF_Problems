#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, L;
ll c[40];

void _main(){
  cin >> n >> L;
  for(int i=0; i<n; ++i)  cin >> c[i];
  for(int i=n; i<30; ++i) c[i] = (ll)1e18;
  for(int i=1; i<30; ++i) c[i] = min(c[i], c[i-1] << 1);
  ll ans = (ll)1e18;
  ll cur = 0, pre = (ll)1e18;
  for(int i=29; i>=0; --i){
    if(L >> i & 1){
      ans = min(ans, cur + pre);
      cur += c[i];
    }
    pre = min(pre, c[i]);
  }
  cout << min(ans, cur) << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}