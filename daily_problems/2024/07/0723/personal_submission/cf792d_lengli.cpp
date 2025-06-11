/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,q;
    std::cin>>n>>q;

    int mx=0;
    while((1ll<<mx)-1<n) mx++;
    std::vector<int> d(mx+2,-1),up(mx+2,-1);
    for(int j=mx-2,l=1;j>=0;j--,l*=2) d[j]=l;
    for(int j=mx-1,l=1;j>=1;j--,l*=2) up[j]=l;

    while(q--){
        int m;
        std::string s;
        std::cin>>m>>s;

        auto find=[&](int u){
            if(u<0 or u>n) return -1000000000ll;
            int root=(n+1)/2,dep=0;
            while(root!=u){
                if(u<root) root=root-d[dep];
                else root=root+d[dep];
                dep++;
            }   
            return dep;
        };
        int dep=find(m);
        int u=m;
        for(auto x:s){
            if(x=='U'){
                if(!dep) continue;
                int v=u+up[dep];
                if(find(v)==dep-1) u=v;
                else{
                    v=u-up[dep];
                    if(find(v)==dep-1) u=v;
                }
                dep--;
            }else if(x=='L'){
                if(d[dep]==-1) continue;
                u-=d[dep];
                dep++;
            }else{
                if(d[dep]==-1) continue;
                u+=d[dep];
                dep++;
            }
        }
        std::cout<<u<<"\n";
    }

    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
