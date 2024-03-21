#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int T;
ll x, y, p, q;

void _main(){
  cin >> T;
  while(T--){
    cin >> x >> y >> p >> q;
    if(x * q == y * p){
      cout << "0\n";
    } else if(p == q && x < y){
      cout << "-1\n";
    } else if(p == 0){
      cout << "-1\n";
    } else {
      ll d = (x + p - 1) / p;
      d = max(d, (y + q - 1) / q);
      d = max(d, (y - x + q - p - 1) / (q - p));
      q *= d;
      cout << q - y << '\n';
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}