/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]+=c;}
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::vector<std::vector<int>> qr(n+2);

    for(int i=1;i<=n;i++){
        int idx=std::min(a[i],i-1);
        qr[idx].pb(i);
    }
    BIT tr(200010);
    long long res=0;
    for(int i=1;i<=n;i++){
        tr.add(std::min(200000,a[i]),1);
        for(auto x:qr[i]){
            res+=i-tr.sum(x-1);
        }
    }
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
