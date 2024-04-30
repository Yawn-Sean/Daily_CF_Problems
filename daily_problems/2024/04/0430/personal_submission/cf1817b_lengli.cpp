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

const int N=2010;

vector<int> eg[N];
int st[N];
vector<int> stk,ans;

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) eg[i].clear();
    stk.clear(),ans.clear();

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }
    int root,flag;

    function<void(int,int)> dfs=[&](int u,int fa){
        if(flag) return;
        if(u==root and st[u]){
            flag=1,ans=stk;
            return;
        }
        if(st[u]) return;
        st[u]=1;
        stk.pb(u);
        for(auto x:eg[u]){
            if(x!=fa) dfs(x,u);
            if(flag) return;
        }
        stk.pop_back();
        st[u]=0;
    };

    auto print=[&](int u){
        cout<<"YES"<<endl;
        vector<array<int,2>> q;
        vector<int> p;
        set<int> s;
        for(auto x:eg[u]){
            if(!st[x]) p.pb(x);
            s.insert(x);
        }
        while(p.size()<2){
            p.pb(ans.back());
            ans.pop_back();
            while(ans.size() and !s.count(ans.back())){
                ans.pop_back();
            }
        }
        q.pb({ans.back(),u});
        while(ans.size()){
            auto v=ans.back();
            ans.pop_back();
            if(ans.size()) q.pb({ans.back(),v});
        }
        q.pb({p[0],u});q.pb({p[1],u});
        cout<<q.size()<<endl;
        for(auto [u,v]:q){
            cout<<u<<" "<<v<<endl;
        }
    };

    for(int i=1;i<=n;i++){
        if(eg[i].size()<4) continue;
        for(int i=1;i<=n;i++) st[i]=0;
        stk.clear();
        root=i,flag=0;
        dfs(i,0);
        if(flag){
            print(i);
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
