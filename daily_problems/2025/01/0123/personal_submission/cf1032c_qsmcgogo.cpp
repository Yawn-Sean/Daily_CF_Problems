#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[202202],b[1102010];
long long dp[221222][6];
const int mod=998244353;
vector<int>g[202020];
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int i,j,x,k;
    int l,r,n,m;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=5;i++)dp[1][i]=1;
    for(i=2;i<=n;i++){
      for(j=1;j<=5;j++){
        if(dp[i-1][j]){
          for(k=1;k<=5;k++){
            if(a[i]==a[i-1]&&j!=k)dp[i][k]=j;
            if(a[i]<a[i-1]&&j>k)dp[i][k]=j;
            if(a[i]>a[i-1]&&j<k)dp[i][k]=j;
          }
        }
      }
    }
    for(i=1;i<=5;i++){
      if(dp[n][i])break;
    }
    if(i==6){
      cout<<-1;
      return 0;
    }
    vector<int>v;
    v.push_back(i);
    j=dp[n][i];
    for(i=n-1;i>=1;i--){
      v.push_back(j);
      j=dp[i][j];
    }
    for(i=n-1;i>=0;i--)cout<<v[i]<<" ";
  }
}
