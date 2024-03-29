#include<bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e3 + 10;

int n, a[N];

void _main(){
  cin >> n;
  int cnt = 0;
  for(int i=1; i<=n; ++i){
    cin >> a[i];
    if(a[i] == 1) ++cnt;
  }
  if(cnt > 0){
    cout << n - cnt << '\n';
    return;
  }
  int ans = inf;
  for(int i=1; i<=n; ++i){
    int val = a[i];
    for(int j=i+1; j<=n; ++j){
      val = gcd(val, a[j]);
      if(val == 1){
        ans = min(ans, j - i + n - 1);
        break;
      }
    }
  }
  if(ans == inf)  ans = -1;
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}