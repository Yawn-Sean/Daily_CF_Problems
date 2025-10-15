/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,l,x,y;
    std::cin>>n>>l>>x>>y;

    bool sx=0,sy=0;

    std::vector<int> a(n);
    std::set<int> s;

    for(int i=0;i<n;i++){
        std::cin>>a[i];
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        if(s.count(a[i]+x)) sx=1;
        if(s.count(a[i]+y)) sy=1;
    }
    if(sx and sy){
        std::cout<<0<<"\n";
        return;
    }

    if(sx){
        std::cout<<1<<"\n"<<y<<"\n";
        return;
    }
    if(sy){
        std::cout<<1<<"\n"<<x<<"\n";
        return;
    }

    for(int i=0;i<n;i++){
        int v=a[i]+x;
        if(v<=l and (s.count(v-y) or s.count(v+y))){
            std::cout<<1<<"\n"<<v<<"\n";
            return;
        }
        v=a[i]-x;
        if(v>=0 and (s.count(v-y) or s.count(v+y))){
            std::cout<<1<<"\n"<<v<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        int v=a[i]+y;
        if(v<=l and (s.count(v-x) or s.count(v+x))){
            std::cout<<1<<"\n"<<v<<"\n";
            return;
        }
        v=a[i]-y;
        if(v>=0 and (s.count(v-x) or s.count(v+x))){
            std::cout<<1<<"\n"<<v<<"\n";
            return;
        }
    }
    std::cout<<2<<"\n"<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
