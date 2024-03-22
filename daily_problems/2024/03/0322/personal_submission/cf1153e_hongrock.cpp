#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

vector<int> ans;
int n;

int query(int x1, int y1, int x2, int y2){
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  cout.flush();
  cin >> x1;
  return x1;
}

void query(int r, bool f){
  int L = 1, R = n;
  int mid, v;
  while(L < R){
    mid = (L + R) >> 1;
    if(f){
      v = query(r, L, r, mid);
    } else {
      v = query(L, r, mid, r);
    }
    if(v & 1){
      R = mid;
    } else {
      L = mid + 1;
    }
  }
  if(f){
    ans.pb(r); ans.pb(L);
  } else{
    ans.pb(L); ans.pb(r);
  }
}

void solve(){
  int cnt = 0;
  for(int i=1; i<n; ++i){
    int v = query(i, 1, i, n);
    if(v & 1){
      ++cnt;
      query(i, 1);
    }
  }
  if(cnt == 1){
    query(n, 1);
    return;
  }
  if(cnt == 2)  return;
  cnt = 0;
  for(int i=1; i<n; ++i){
    int v = query(1, i, n, i);
    if(v & 1){
      ++cnt;
      query(i, 0);
    }
  }
  if(cnt == 1){
    query(n, 0);
  }
}

void _main(){
  cin >> n;
  solve();
  cout << "!";
  for(int v : ans)  cout << ' ' << v;
  cout << '\n';
  cout.flush();
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
