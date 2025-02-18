/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::set<std::array<int,2>> s;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        s.insert({u,v});
        s.insert({v,u});
    }
    int x=-1,y=-1;
    for(int i=0;i<n and x==-1;i++){
        for(int j=0;j<n;j++){
            if(i!=j and !s.count({i,j})){
                x=i,y=j;
                break;
            }
        }
    }
    if(x==-1){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::vector<int> a(n,0),b(n,0);
    a[x]=1,b[x]=b[y]=1;
    for(int i=0,j=3;i<n;i++){
        if(i==y) a[i]=2;
        else if(!a[i]){
            a[i]=b[i]=j;
            j++;
        }
    }
    std::cout<<"YES"<<"\n";
    for(auto x:a) std::cout<<x<<" ";std::cout<<"\n";
    for(auto x:b) std::cout<<x<<" ";std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
