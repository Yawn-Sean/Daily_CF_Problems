#include<bits/stdc++.h>
using namespace std;
const long long INF=-(1LL<<60);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<int>> g(n+1);
    for(int i=2,p;i<=n;++i){
        cin>>p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    vector<int> par(n+1),dep(n+1);
    vector<int> ord;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ord.push_back(u);
        for(int v:g[u]){
            if(v!=par[u]){
                par[v]=u;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    vector<long long> best(n+1);
    for(int i=n-1;i>=0;--i){
        int u=ord[i];
        long long cur=a[u]+dep[u];
        for(int v:g[u]) if(v!=par[u]) cur=max(cur,best[v]);
        best[u]=cur;
    }
    long long ans=0;
    for(int u=1;u<=n;++u){
        long long m1=INF,m2=INF;
        long long o=a[u]+dep[u];
        if(o>m1){
            m2=m1;
            m1=o;
        }
        else if(o>m2) m2=o;
        for(int v:g[u]){
            if(v!=par[u]){
                long long v2=best[v];
                if(v2>m1){
                    m2=m1;
                    m1=v2;
                }
                else if(v2>m2) m2=v2;
            }
        }
        if(m2!=INF) ans=max(ans,m1+m2-2*dep[u]);
    }
    cout<<ans<<'\n';
}
