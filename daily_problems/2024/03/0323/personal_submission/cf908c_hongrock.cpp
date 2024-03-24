#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e3 + 10;

int n, r, x[N];
double y[N];

void _main(){
  cin >> n >> r;
  int R = (r * 2) * (r * 2);
  for(int i=1; i<=n; ++i){
    cin >> x[i];
    y[i] = r;
    for(int j=1; j<i; ++j){
      int d = abs(x[i] - x[j]);
      if(d > r * 2){
        continue;
      }
      y[i] = max(y[i], y[j] + sqrt(R - d * d));
    }
    cout << fixed << setprecision(8) << y[i] << " \n"[i == n];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
