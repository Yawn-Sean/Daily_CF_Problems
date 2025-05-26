#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>p(n);
    for(auto&i:p)cin>>i.first>>i.second;
    sort(p.begin(),p.end());
    vector<vector<int>>dp(n,vector<int>(2,1e18));
    dp[0][1]=p[0].second;
    for(int i=1;i<n;i++){
        for(int j=i-1,sum=p[i].first,cnt=1;j>=0;j--,cnt++){
            dp[i][0]=min(dp[i][0],dp[j][1]+sum-p[j].first*cnt);
            sum+=p[j].first;
        }
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i].second;
    }
    cout<<min(dp[n-1][0],dp[n-1][1]);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}