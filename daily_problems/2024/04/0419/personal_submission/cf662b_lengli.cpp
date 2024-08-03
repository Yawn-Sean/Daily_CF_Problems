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

int n,m;
vector<array<int,2>> eg[N];

pair<int,vector<int>> check(int x){
    vector<int> st0(n+1,0),sta0(n+1,0);
    vector<int> st1(n+1,0),sta1(n+1,0);
    bool flag0=1,flag1=1;
    function<void(int,int,int,vector<int>&,vector<int>&,vector<int>&,bool&)> dfs=[&](int u,int use,int col,vector<int> &st,vector<int> &sta,vector<int> &tmp,bool &flag){
        if(st[u]){
            if(sta[u]!=use) flag=0;
            return;
        }
        st[u]=1;
        if(use) tmp.pb(u);
        sta[u]=use;
        for(auto [v,c]:eg[u]){
            if(st[v]){
                if(c==col and (use+sta[v])&1) flag=0;
                else if(c!=col and (use+sta[v])%2==0) flag=0;
                continue;
            }
            if(use) c^=1;
            if(c==col) dfs(v,0,col,st,sta,tmp,flag);
            else dfs(v,1,col,st,sta,tmp,flag);
        }
    };

    vector<int> q,p,res;
    for(int i=1;i<=n;i++){
        q.clear(),p.clear();
        flag0=flag1=1;
        if(!st0[i]) dfs(i,0,x,st0,sta0,q,flag0);
        if(!st1[i]) dfs(i,1,x,st1,sta1,p,flag1);

        if(!flag0 and !flag1) return {-1,{}};
        if(!flag0) for(auto x:p) res.pb(x);
        else if(!flag1) for(auto x:q) res.pb(x);
        else if(p.size()<q.size()) for(auto x:p) res.pb(x);
        else for(auto x:q) res.pb(x);
    }
    return {res.size(),res};
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b;
        char x;
        cin>>x;
        c=(x=='B' ? 0 : 1);
        eg[a].pb({b,c});
        eg[b].pb({a,c});
    }
    
    auto r1=check(0);
    auto r2=check(1);
    if(r1.first==-1 and r2.first==-1) cout<<-1<<endl;
    else if(r1.first==-1){
        cout<<r2.second.size()<<endl;
        for(auto x:r2.second) cout<<x<<" ";
    }else if(r2.first==-1){
        cout<<r1.second.size()<<endl;
        for(auto x:r1.second) cout<<x<<" ";
    }else if(r1.first<r2.first){
        cout<<r1.second.size()<<endl;
        for(auto x:r1.second) cout<<x<<" ";
    }else{
        cout<<r2.second.size()<<endl;
        for(auto x:r2.second) cout<<x<<" ";
    }

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
