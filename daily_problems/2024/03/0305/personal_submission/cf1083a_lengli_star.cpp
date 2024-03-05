//定义dp(i)为从i点向下的路径最大权值和
//那么dfs到点u的时候，我们考虑最高点为点u路径最大值
//很显然从子节点x中找到向下的最大和次大的两个dp(x)，更新即可，注意路径贡献为负
//处理完一个点后更新答案即可

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<array<int,2>>> eg(n+1);
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        eg[a].pb({b,c});
        eg[b].pb({a,c});
    }
    vector<int> f(n+2,0);

    int res=0;
    function<void(int,int)> dfs=[&](int u,int fa){
        int fma=0,sma=0;
        for(auto [x,w]:eg[u]){
            if(x==fa) continue;
            dfs(x,u);
            int t=-w+f[x];
            if(t>fma) sma=fma,fma=t;
            else if(t>sma) sma=t;
        }
        res=max(res,fma+sma+a[u]);
        f[u]=fma+a[u];
    };
    dfs(1,0);
    cout<<res;
    
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
