#include<bits/stdc++.h>
using namespace std;
const int N =5100;
const int mod=1e9+7;
typedef long long ll;
vector<pair<int,double>> pt(N);
vector<int> cnt(N,0);
void solve(){
	int n,m;cin>>n>>m;int cur=1,ans=0,dp[N];
    for(int i=1;i<=n;i++)
    {
        int x;double y;cin>>x>>y;
        pt[i].first=x;
        pt[i].second=y;
        cnt[x]++;
        dp[i]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(pt[i].first>=pt[j].first)
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<n-ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
