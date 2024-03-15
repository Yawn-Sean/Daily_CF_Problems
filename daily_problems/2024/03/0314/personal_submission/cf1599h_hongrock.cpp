#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

ll query(ll x, ll y){
  cout << "? " << x << ' ' << y << '\n';
  cout.flush();
  cin >> x;
  return x;
}

void _main(){
  ll n = 1000000000;
  ll d1 = query(1, 1);
  ll d2 = query(n, 1);
  ll m = (d1 - d2 + n + 1) / 2;
  ll lft = query(m, 1);
  ll rgt = query(m, n);
  ll y1 = lft + 1, y2 = n - rgt;
  ll x1 = d1 - y1 + 2;
  ll x2 = d1 - d2 + n + 1 - x1;
  cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  cout.flush();
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
