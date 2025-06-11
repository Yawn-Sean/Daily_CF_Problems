#include<bits/stdc++.h>
using namespace std;
const int N=2010;
std::vector<int>e[N];
int n,m;
int dep[N],c[N],f[N];

struct cmp{
    bool operator()(int a,int b){
        return dep[a]>dep[b];
    }
};

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(i);
        e[i].push_back(a);
        c[i]=b;
    }
    priority_queue<int,vector<int>,cmp>q;

    auto dfs=[&](auto &&dfs,int u,int fa)->void{
        f[u]=fa;dep[u]=dep[fa]+1;
        for(int v:e[u]){
            if(v==fa)continue;
            dfs(dfs,v,u);
        }
        if(c[u]==0&&u!=0)q.push(u);
    };
    dfs(dfs,0,-1);
    int cnt=0;
    vector<int>ans(n+1);
    while(q.size()){
        int u=q.top();q.pop();
    
        cnt++;
        ans[u]=cnt;
        //cout<<u<<" "<<cnt<<"\n";
        while(u){
            c[u]--;
            if(c[u]==0)q.push(u);
            u=f[u];
        }
    }
    if(cnt==n){
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        return;
    }
    cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
