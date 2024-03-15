//由于所有操作后在输出，故可以将操作先存在所有点上，然后dfs一遍
//对于某个点的操作，我们递归其子树的时候，只需要在dep[v]>dep[u]的时候去掉u点的贡献即可
//所以采用差分，然后递归回来要记得去掉当前子树的所有差分记录，即可。

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

const int N=300010;

vector<int> eg[N];
vector<array<int,2>> q[N];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int v,d,x;
        cin>>v>>d>>x;
        q[v].pb({x,d});
    }
    vector<int> b(n+1,0);
    vector<int> res(n+1,0);
    function<void(int,int,int,int)> dfs=[&](int u,int f,int sum,int dep){
        int bkp=sum;sum+=b[dep];
        for(auto [x,d]:q[u]) {
            sum+=x;
            if(dep+d+1<=n) b[dep+d+1]+=-x;
        }
        res[u]=sum;

        for(auto x:eg[u]){
            if(x==f) continue;
            dfs(x,u,sum,dep+1);
        }

        for(auto [x,d]:q[u]) {
            if(dep+d+1<=n) b[dep+d+1]-=-x;
        }

        sum=bkp;
    };

    dfs(1,0,0,0);
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
