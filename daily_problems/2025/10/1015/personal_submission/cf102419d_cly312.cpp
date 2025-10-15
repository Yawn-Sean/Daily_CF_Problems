#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<pair<int,int>> e(m);
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        e[i]={u,v};
        if(a[u]==a[v]){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    vector<int> c(n+1,-1);
    bool ok=1;
    for(int i=1;i<=n&&ok;++i){
        if(c[i]!=-1) continue;
        queue<int> q;
        q.push(i);
        c[i]=0;
        while(!q.empty()&&ok){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(c[v]==-1){
                    c[v]=1-c[u];
                    q.push(v);
                }else if(c[v]==c[u]){
                    ok=0;
                    break;
                }
            }
        }
    }
    if(!ok){
        cout<<-1<<'\n';
        return 0;
    }
    const int V=1<<20;
    vector<bool> ban(V);
    for(auto &p:e){
        int u=p.first,v=p.second;
        if(c[u]!=c[v]) ban[a[u]^a[v]]=1;
    }
    int x=0;
    while(x<V&&ban[x]) ++x;
    vector<int> ans;
    for(int i=1;i<=n;++i)if(c[i]==1) ans.push_back(i);
    cout<<ans.size()<<' '<<x<<'\n';
    for(int i:ans) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
