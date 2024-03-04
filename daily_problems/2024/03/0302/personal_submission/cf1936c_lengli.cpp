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

vector<vector<array<int,2>>> eg;

int dijkstra(int S,int n){
    vector<int> dist(n+1,-1);
    vector<bool> st(n+1,0);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    q.push({0,S});dist[S]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(st[t[1]]) continue;
        st[t[1]]=1;
        for(auto [x,w]:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+w){
                dist[x]=t[0]+w;
                q.push({dist[x],x});
            }
        }
    }
    return dist[1];
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<vector<int>> a(n,vector<int>(m));
    for(auto &x:a) for(auto &y:x) cin>>y;
    eg.clear();
    eg.resize(2*n*m+n+1);

    for(int i=0;i<m;i++){
        vector<array<int,2>> q;
        for(int j=0;j<n;j++) q.pb({a[j][i],j+1});
        sort(all(q));

        auto getu=[&](int x){
            return 2*n*i+n+x;
        };
        auto getd=[&](int x){
            return 2*n*(i+1)+x;
        };

        for(int j=0;j<n;j++){
            auto [v,id]=q[j];
            auto u=getu(id),d=getd(id);
            //cout<<i<<" "<<id<<" "<<u<<" "<<d<<endl;
            eg[id].pb({u,c[id]});
            eg[u].pb({d,0});
            eg[d].pb({id,0});
            if(j+1<n){
                int nu=getu(q[j+1][1]);
                int w=abs(q[j+1][0]-v);
                eg[u].pb({nu,w});
            }
            if(j){
                int ld=getd(q[j-1][1]);
                eg[d].pb({ld,0});
            }
        }
    }

    cout<<dijkstra(n,2*n*m+n)<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
