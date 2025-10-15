/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> c(2*n+1),pos(2*n+1),ok(2*n+1);
    for(int i=1;i<=n*2;i++){
        std::cin>>c[i];
        pos[c[i]]=i;
    }
    std::vector<std::array<int,2>> w;
    for(int i=2*n;i>=1;i--){
        if(ok[i]) continue;
        int cnt=0;
        for(int j=pos[i];j<=2*n;j++){
            if(ok[c[j]]) break;
            cnt++;
            ok[c[j]]=1;
        }
        w.pb({i,cnt});
    }
    std::vector<int> dp(n+1);
    dp[0]=1;
    std::vector<std::array<int,2>> vis(n+1);
    for(int i=w.size()-1;i>=0;i--){
        auto [v,c]=w[i];
        for(int j=n-c;j>=0;j--){
            if(dp[j]){
                dp[j+c]=1;
                if(!vis[j+c][0]) vis[j+c]={v,c};
            }
        }
    }
    if(!dp[n]){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<int> ans1(n+1);
    std::vector<int> use(2*n+1);
    for(int i=n;i>=1;i-=vis[i][1]){
        for(int j=i,cnt=vis[i][1];j>i-vis[i][1];j--,cnt--){
            ans1[j]=c[pos[vis[i][0]]+cnt-1];
            use[pos[vis[i][0]]+cnt-1]=1;
        }
    }
    for(int i=1;i<=n;i++){
        std::cout<<ans1[i]<<" ";
    }std::cout<<"\n";

    for(int i=1;i<=2*n;i++){
        if(!use[i]){
            std::cout<<c[i]<<" ";
        }
    }
    std::cout<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
