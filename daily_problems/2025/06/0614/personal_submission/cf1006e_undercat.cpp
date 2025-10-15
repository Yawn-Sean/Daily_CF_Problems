#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>g[n+1],son(n+1),now(n+1),f;
    for(int i=2,p;i<=n;i++){
        cin>>p;
        g[p].push_back(i);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    function<void(int)>dfs=[&](int u)->void{
        son[u]=1;
        now[u]=(int)f.size();
        f.push_back(u);
        for(auto i:g[u]){
            dfs(i);
            son[u]+=son[i];
        }
    };
    dfs(1);
    while(q--){
        int u,k;cin>>u>>k;
        if(son[u]<k){
            cout << "-1" << endl;
        }else{
            cout << f[now[u]+k-1] << endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
