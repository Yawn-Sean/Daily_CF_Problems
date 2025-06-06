/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

struct node{
    std::string s;
    int a,b;
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<node> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i].s>>a[i].a;
    }
    sort(all(a),[&](auto l,auto r){
        return l.a<r.a;
    });
    for(int i=0;i<n;i++){
        if(a[i].a>i){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        a[i].b=inf-a[i].a;
        for(int j=0;j<i;j++){
            if(a[j].b<=a[i].b) a[j].b--;
        }
    }
    for(auto x:a){
        std::cout<<x.s<<" "<<x.b<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
