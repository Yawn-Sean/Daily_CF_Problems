#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int n, dp[N];

void _main(){
  cin >> n;
  int x;
  for(int i=0; i<n; ++i){
    cin >> x;
    ++dp[x];
  }
  int ans = 0;
  for(int i=N-1; i>=1; --i){
    int cur = 0;
    for(int j=i<<1; j<N; j+=i){
      cur = max(cur, dp[j]);
    }
    dp[i] += cur;
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}