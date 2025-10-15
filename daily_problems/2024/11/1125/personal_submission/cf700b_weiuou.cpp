#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans = 0;
vector<int>cnt;
int dfs(int idx,int fa,vector<vector<int>>&g){
  int res = cnt[idx];
  for(auto x:g[idx]){
    if(x==fa)continue;
    res+=dfs(x,idx,g);
  }
  ans += min(res,2*k-res);
  return res;
}
int main(){
  cin>>n>>k;
  cnt = vector<int>(n+1,0);
  vector<vector<int>>g(n+1);
  for(int i=0;i<k*2;i++){
    int tmp;
    cin>>tmp;
    cnt[tmp] = 1;
  }
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,0,g);
  cout<<ans<<endl;
}
