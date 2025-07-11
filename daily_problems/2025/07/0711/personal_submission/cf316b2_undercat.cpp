#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n+1),head(n+1),res;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        head[a[i]]=1;
    }
    vector<int>dp(n+1);
    dp[0]=1;
    int p=0;
    for(int i=1;i<=n;i++)if(!head[i]){
        int now=i,cnt=0,flag=0;
        while(now){
            cnt++;
            if(now==x){
                flag=true;
                p=cnt;
            }
            now=a[now];
        }
        if(flag)p=cnt+1-p;
        else{
            for(int j=n;j>=cnt;j--){
                if(dp[j-cnt])dp[j]=1;
            }
        }
    }
    for(int i=0;i<=n;i++)if(dp[i])cout<<i+p<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}