#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[302200];
int b[202020];
vector<int>g[202000];
pair<int,int>p[302020];
int out[303030];
int dp[2303030]; 
int mp[303030];
vector<vector<int>>v[2];
signed main(){
  // ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int i,j,k,x,y,z,m;
    int n,q;
    cin>>n>>m>>k;
    memset(dp,0x3f,sizeof(dp));
    int sum=0;
    for(i=1;i<=n;i++)mp[i]=1e8,sum+=mp[i];
    for(i=1;i<=m;i++){
      int x,y,z,h;
      cin>>x>>y>>z>>h;
      if(z==0){
        v[0].push_back({x,y,h});
      }
      else{
        v[1].push_back({x,z,h});
      }
    }
    if(v[0].empty()||v[1].empty())return cout<<-1,0;
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    i=0;
    set<int>s;
    for(j=1;j<=1e6;j++){
      dp[j]=min(dp[j],dp[j-1]);
      while(i<v[0].size()&&v[0][i][0]==j){
        s.insert(v[0][i][1]);
        if(mp[v[0][i][1]]>v[0][i][2]){
          sum-=mp[v[0][i][1]];
          mp[v[0][i][1]]=v[0][i][2];
          sum+=mp[v[0][i][1]];
        }
        if(s.size()==n){
          dp[j]=min(dp[j],sum);
        }
        i++;
      }
    }
    s.clear();
    sum=0;
    for(i=1;i<=n;i++)mp[i]=1e8,sum+=mp[i];
    i=v[1].size()-1;
    int res=1e18;
    for(j=1e6;j>=k+1;j--){
      while(i>=0&&v[1][i][0]==j){
        s.insert(v[1][i][1]);
        if(mp[v[1][i][1]]>v[1][i][2]){
          sum-=mp[v[1][i][1]];
          mp[v[1][i][1]]=v[1][i][2];
          sum+=mp[v[1][i][1]];
        }
        if(s.size()==n){
          res=min(res,sum+dp[j-k-1]);
        }
        i--;
      }
    }
    if(res<1e17)
      cout<<res;
    else cout<<-1;
  }

  
}
/*

2 6 9
1 1 0 5000
3 2 0 5500
2 2 0 6000
15 0 2 9000
9 0 1 7000
8 0 2 6500

*/
