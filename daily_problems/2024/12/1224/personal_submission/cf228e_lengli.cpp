/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1010;

int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}


void solve(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n*2;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        std::cin>>x>>y>>z;
        if(!z){
            p[find(x)]=p[find(y+n)];
            p[find(x+n)]=p[find(y)];
        }else{
            p[find(x)]=p[find(y)];
            p[find(x+n)]=p[find(y+n)];
        }
    }
    for(int i=1;i<=n;i++){
        if(find(i)==find(i+n)){
            std::cout<<"Impossible"<<"\n";
            return;
        }
    }
    std::map<int,int> st;
    std::vector<int> res;
    for(int i=1;i<=n;i++){
        int u=find(i),v=find(i+n);
        if(!st[u] and !st[v]) st[u]=1;
        if(st[u]) res.pb(i);
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
