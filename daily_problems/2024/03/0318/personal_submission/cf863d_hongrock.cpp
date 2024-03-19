#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, Q, m, a[N];
int op[N], l[N], r[N];

void _main(){
  cin >> n >> Q >> m;
  for(int i=1; i<=n; ++i) cin >> a[i];
  for(int i=1; i<=Q; ++i) cin >> op[i] >> l[i] >> r[i];
  for(int i=1; i<=m; ++i){
    int p;
    cin >> p;
    for(int j=Q; j>=1; --j){
      if(p < l[j] || p > r[j])  continue;
      if(op[j] == 1){
        --p;
        if(p < l[j])  p = r[j];
      } else {
        p = l[j] + r[j] - p;
      }
    }
    cout << a[p] << " \n"[i == m];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
