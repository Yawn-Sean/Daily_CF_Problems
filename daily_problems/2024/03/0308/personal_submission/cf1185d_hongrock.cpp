#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n;
pii a[N];

bool ok(int d, int st){
  int k = st == 1 ? -1 : a[1].second;
  int pre = a[st].first;
  for(int i=st+1; i<=n; ++i){
    if(a[i].first - pre != d){
      if(k != -1) return 0;
      k = a[i].second;
    } else {
      pre = a[i].first;
    }
  }
  if(k == -1){
    k = a[n].second;
  }
  cout << k << '\n';
  return 1;
}

void _main(){
  cin >> n;
  for(int i=1; i<=n; ++i){
    cin >> a[i].first;
    a[i].second = i;
  }
  if(n <= 3){
    cout << "1\n";
    return;
  }
  sort(a + 1, a + 1 + n);
  vector<pii> g;
  g.pb(a[2].first - a[1].first, 1);
  g.pb(a[3].first - a[1].first, 1);
  g.pb(a[3].first - a[2].first, 2);
  for(auto [d, st] : g){
    if(ok(d, st)){
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
