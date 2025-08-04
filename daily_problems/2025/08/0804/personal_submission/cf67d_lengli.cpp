/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]=std::max(a[i],c);}
    int sum(int x){
        int res=0;
        for(int i=x;i;i-=lowbit(i)) res=std::max(a[i],res);
        return res;
    }
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    std::vector<int> tmp(n+2),b(n+2);
    for(int i=1;i<=n;i++) std::cin>>tmp[i];
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        b[x]=i;
    }
    for(int i=1;i<=n;i++) a[i]=b[tmp[i]];
    
    std::reverse(all(a));

    std::vector<int> f(n+2,1);

    BIT tr(n);

    for(int i=1;i<=n;i++){
        f[i]=std::max(f[i],tr.sum(a[i]-1)+1);
        tr.add(a[i],f[i]);
    }
    std::cout<<*std::max_element(all(f))<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
