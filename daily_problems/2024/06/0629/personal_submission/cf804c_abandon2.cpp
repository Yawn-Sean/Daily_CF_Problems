#include<bits/stdc++.h>
using namespace std;
const int N =3e5+10;

std::vector<int> e[N],g[N];
map<int,int>mp,mq;
int c[N];

void dfs(int u,int fa){
    mp.clear();
    
    for(int v:g[u]){
        if(c[v]){
            mp[c[v]]=1;
        }  
    }
    
    int t=0;
    for(int v:g[u]){
        if(!c[v]){
            while(1){
                if(!mp[++t]){
                    break;
                }
            }
            c[v]=t;
        }
    }
    
    for(int v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}


void solve(){
    int n,m;cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mx=max(mx,x);
        while(x--){
            int t;cin>>t;
            g[i].push_back(t);
        }
    }

    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,0);
    cout<<mx<<"\n";
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

/*
9
1 2 1 2 2 3 3 5 3 3 4 1 4 2 5 6 1 7 2 2 3 6 5 3 4 4 4 6 7 7 5 3 8 8 9 
*/
