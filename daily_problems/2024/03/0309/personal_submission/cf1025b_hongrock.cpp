#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, a[N], b[N];
set<int> st;

void add(int x){
  for(int i=2; i*i<=x; ++i){
    if(x % i == 0){
      st.insert(i);
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) st.insert(x);
}

bool ok(int v){
  for(int i=1; i<=n; ++i){
    if(a[i] % v && b[i] % v){
      return 0;
    }
  }
  return 1;
}

void _main(){
  cin >> n;
  for(int i=1; i<=n; ++i) cin >> a[i] >> b[i];
  add(a[1]);
  add(b[1]);
  for(int v : st){
    if(ok(v)){
      cout << v << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
