/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> eg(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }

    vector<int> st(n+1,0);
    bool flag=0;
    vector<int> q,res;

    function<void(int,int,int)> dfs=[&](int u,int f,int len){
        if(flag) return;
        st[u]=len;
        q.pb(u);
        for(auto x:eg[u]){
            if(x==f) continue;
            if(!st[x]) dfs(x,u,len+1);
            else{
                int d=st[u]-st[x]+1;
                if(d>k){
                    res.clear();
                    for(int i=0;i<q.size();i++){
                        if(q[i]==x){
                            for(int j=i;j<q.size();j++){
                                res.pb(q[j]);
                            }
                            break;
                        }
                    }
                    flag=1;
                    return;
                }
            }
            if(flag) return;
        }
        st[u]=0;
        q.pop_back();
    };

    dfs(1,0,1);
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<" ";

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
