#include<bits/stdc++.h>
using namespace std;
#define int long long
double a[202200];
int b[202020];
vector<int>g[202000];
double dp[2][201][4040];    //dp[i][j]  前i个 赢了数量为j，总容量为k的概率
double dp2[201][201];   //dp2[i][j]  前i个 赢了j个大奖的概率
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int i,j,k,x,y,z,m;
    int n,q;
    cin>>n>>x>>y;
    vector<pair<int,int>>v[2];
    int s=0;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    for(i=1;i<=n;i++){
      v[b[i]==-1].push_back({a[i],b[i]});
    }
    dp[0][0][0]=1;
    int nn=v[0].size(),nm=v[1].size();
    for(i=0;i<nn;i++){
      for(j=0;j<=i;j++){
        for(k=400;k>=0;k--){
          dp[1][j][k]+=dp[0][j][k]*(100-v[0][i].first)/100;
          dp[1][j+1][min(400LL,k+v[0][i].second)]+=dp[0][j][k]*v[0][i].first/100;
        }
      }
      for(j=0;j<=i+1;j++){
        for(k=400;k>=0;k--){
          dp[0][j][k]=dp[1][j][k];
          dp[1][j][k]=0;
        }
      }
      s+=v[0][i].second;
    }
    dp2[0][0]=1;
    for(i=0;i<nm;i++){
      for(j=i;j>=0;j--){
        dp2[i+1][j]+=dp2[i][j]*(100-v[1][i].first)/100;
        dp2[i+1][j+1]+=dp2[i][j]*v[1][i].first/100;
      }
    }
    double res=0;
    double yx=0;
    for(i=0;i<=nn;i++){
      for(j=0;j<=nm;j++){
        for(k=0;k<=400;k++){
          if(i+j>=x&&k+y>=j){
            res+=dp[0][i][k]*dp2[nm][j];
          }
        }
      }
    }
    printf("%.6f\n",res);
    
  }

  
}
