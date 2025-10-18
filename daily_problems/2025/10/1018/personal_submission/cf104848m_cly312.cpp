#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    long long T;
    cin>>n>>m>>T;
    vector<vector<pair<int,double>>> g(n);
    while(m--){
        long long u,v,l,c;
        cin>>u>>v>>l>>c;
        u--;v--;
        double w=sqrtl((double)l*c);
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    const double INF=1e30L;
    vector<double>d(n,INF);
    d[0]=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>>q;
    q.push({0,0});
    while(!q.empty()){
        auto [cd,u]=q.top();
        q.pop();
        if(cd>d[u]+1e-12)continue;
        for(auto &[v,w]:g[u]){
            double nd=d[u]+w;
            if(nd<d[v]-1e-12){
                d[v]=nd;
                q.push({nd,v});
            }
        }
    }
    cout<<fixed<<setprecision(10)<<(d[n-1]*d[n-1])/T<<'\n';
}
