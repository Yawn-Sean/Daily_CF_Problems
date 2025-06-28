#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>a(n),du(n),cnt(n),st(n);
    for(auto&i:a)cin>>i,i--,du[i]++;
    for(int i=0;i<n;i++){
        if(du[i]!=1){
            cout<<-1;
            return;
        }
    }
    for(int i=0;i<n;i++)cnt[i]=1;
    auto dfs=[&](auto&&dfs,int u)->void{
        st[u]=1;
        if(st[a[u]])return;
        dfs(dfs,a[u]);
        cnt[u]+=cnt[a[u]];
    };
    int res=1;
    for(int i=0;i<n;i++){
        if(st[i])continue;
        dfs(dfs,i);
        if(cnt[i]%2==0)cnt[i]/=2;
        res=res/__gcd(res,cnt[i])*cnt[i];
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}
