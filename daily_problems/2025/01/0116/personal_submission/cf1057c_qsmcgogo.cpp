#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
pair<int,int>a[55];
int dp[55][2070];  
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int m,i,j,k,tt;
    int n;
    int x,y,c=0;
    cin>>n>>x>>tt;
    for(i=1;i<=n;i++){
      cin>>a[i].first;
      a[i].second=i;
    }
    sort(a+1,a+n+1);
    string s;
    cin>>s;
    memset(dp,0x3f,sizeof(dp));
    int res=1e14;
    for(i=1;i<=n;i++){
      dp[i][a[i].first]=abs(x-a[i].second);
      if(a[i].first>=tt)res=min(res,dp[i][a[i].first]);
      for(j=1;j<i;j++){
        if(a[j].first<a[i].first&&s[a[i].second-1]!=s[a[j].second-1]){
          for(k=a[i].first;k<=tt+50;k++){
            dp[i][k]=min(dp[i][k],dp[j][k-a[i].first]+abs(a[i].second-a[j].second));
            if(k>=tt)res=min(res,dp[i][k]);
          }
        }
      }
    }
    if(res>1e12)res=-1;
    cout<<res;
    
    

  }

    

}
