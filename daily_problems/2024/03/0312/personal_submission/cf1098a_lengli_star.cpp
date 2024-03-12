//对于一个合法树，那么任意一条向下的路径，权值和都是逐渐增大，如果出现逆序，则为-1
//由于给的是前缀和(路径和)，我们考虑差分计算答案。
//由于需要让整棵树的权值和最小，那么对于每一个分叉点，我们肯定希望它能为子树的路径和提供尽可能大的贡献
//那么这个贡献即为子树中的s[son]的最小值。
//那么dfs一遍之后，差分统计答案即可。

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
    vector<vector<int>> eg(n+1,vector<int>());
    vector<int> p(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        p[i]=x;
        eg[x].pb(i);
        eg[i].pb(x);
    }
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        if(s[i]==-1) s[i]=1e18;
    }
    bool flag=1;
    int res=0;
    function<void(int,int,int)> dfs=[&](int u,int f,int dep){
        for(auto x:eg[u]){
            if(x==f) continue;
            s[u]=min(s[x],s[u]);
            dfs(x,u,dep+1);
        }
    };
    dfs(1,0,1);
    for(int i=1;i<=n and flag;i++){
        if(s[p[i]]>s[i]) flag=0;
        if(s[i]!=1e18) res+=s[i]-s[p[i]];
    }
    if(!flag) cout<<-1;
    else cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
