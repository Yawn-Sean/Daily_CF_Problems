#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int T, n, m, Q, op, x;
map<int, int> f;
int g;

vector<pii> factor(int n){
  vector<pii> ret;
  for(int i=2; i*i<=n; ++i){
    if(n % i == 0){
      int c = 0;
      while(n % i == 0){
        n /= i;
        ++c;
      }
      ret.pb(i, c);
    }
  }
  if(n > 1) ret.pb(n, 1);
  return ret;
}

void add(int v, int c){
  g /= (f[v] + 1);
  f[v] += c;
  g *= (f[v] + 1);
}

void add(int n){
  vector<pii> facs = factor(n);
  for(auto [v, c] : facs){
    add(v, c);
  }
}

bool ok(){
  vector<pii> facs = factor(g);
  for(auto [v, c] : facs){
    if(!f.count(v) || c > f[v]) return 0;
  }
  return 1;
}

void _main(){
  cin >> T;
  while(T--){
    cin >> n >> Q;
    m = n;
    f.clear();
    g = 1;
    add(n);
    while(Q--){
      cin >> op;
      if(op == 1){
        cin >> x;
        add(x);
        cout << (ok() ? "YES" : "NO") << '\n';
      } else {
        f.clear();
        g = 1;
        n = m;
        add(n);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}