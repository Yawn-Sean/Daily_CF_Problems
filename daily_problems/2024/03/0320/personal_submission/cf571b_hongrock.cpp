#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 3e5 + 10;
constexpr int M = 5e3 + 10;

int n, k, a[N];
ll dp[M][M];

void upd(ll &x, ll y){
  if(x > y) x = y;
}

void _main(){
  cin >> n >> k;
  for(int i=1; i<=n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int g = n / k;
  int r = n % k;
  for(int i=0; i<=k; ++i){
    for(int j=0; j<=r; ++j) dp[i][j] = (ll)1e18;
  }
  dp[0][0] = 0;
  for(int i=0; i<k; ++i){
    for(int j=0; j<=r; ++j){
      int st = i * g + j + 1;
      upd(dp[i+1][j], dp[i][j] + a[st + g - 1] - a[st]);
      upd(dp[i+1][j+1], dp[i][j] + a[st + g] - a[st]);
    }
  }
  cout << dp[k][r] << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
