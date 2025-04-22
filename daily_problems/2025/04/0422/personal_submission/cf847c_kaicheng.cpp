#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long

void dfs(int n,int k){
  if(n==0){
    return ;
  }
  if(k>=n-1){
    cout<<"(";
    dfs(n-1,k-(n-1));
    cout<<")";
  }
  else{
    cout<<"()";
    dfs(n-1,k);
  }
}


void solve() {
  int n,k;
  cin>>n>>k;
  if(n*(n-1)/2<k){
    cout<<"Impossible"<<'\n';
  }
  else{
    dfs(n,k);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}