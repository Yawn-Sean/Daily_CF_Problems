/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=200010;

struct BIT{
    int n=N-1;
    int a[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
    
    int sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
    
}tr;

void solve(){
    int n;
    std::cin>>n;

    std::vector<int> a(n+2);
    std::vector<int> q;
    for(int i=1;i<=n;i++) std::cin>>a[i],q.pb(a[i]);

    sort(all(q));
    q.erase(unique(all(q)),q.end());
    auto get=[&](int x){
        return upper_bound(all(q),x)-q.begin();
    };

    long long res=0;

    for(int i=1;i<=n;i++){
        int l=tr.sum(get(a[i]-1));
        int r=(i-1)-tr.sum(get(a[i]));
        res+=std::min(1ll*l,1ll*r);
        tr.add(get(a[i]),1);
    }
    for(int i=1;i<=n;i++) tr.add(get(a[i]),-1);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
