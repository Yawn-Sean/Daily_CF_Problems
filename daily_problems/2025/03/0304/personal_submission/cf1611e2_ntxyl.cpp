#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>dp(n+1,n);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        dp[x]=0;
    }

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    auto dfs=[&](auto &&dfs,int u,int fa,int t)->int{
        int ans=0;
        bool st=0;
        for(auto v:p[u]){
            if(v==fa) continue;
            int c=dfs(dfs,v,u,t+1);
            if(c<0) st=1;
            dp[u]=min(dp[u],dp[v]+1);
            ans+=c;
        }
        if(t>=dp[u]) return 1; //在我到达之前朋友到达
        if(ans==0||st) return -1; //子树没封住
        return ans;
    };
    cout<<dfs(dfs,1,0,0)<<endl;
}
signed main() {
    fastio;
    int T;
//  T = 1;
    cin>>T;
    while (T--) solve();

    return 0;
}
