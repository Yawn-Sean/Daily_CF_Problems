#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

ll n,a[N],dp[N][2];//dp[u][0/1]:u节点减dp[u][0]次，加dp[u][1]次
vector<int>g[N];

il void dfs(int u,int fa){
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        dp[u][0]=max(dp[u][0],dp[v][0]);
        dp[u][1]=max(dp[u][1],dp[v][1]);
    }
    ll ans=a[u]+dp[u][1]-dp[u][0];
    if(ans>0){
        dp[u][0]+=ans;
    }else{
        dp[u][1]-=ans;
    }
}

il void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<dp[1][0]+dp[1][1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {
    
        solve();

    }

    return 0;
}
