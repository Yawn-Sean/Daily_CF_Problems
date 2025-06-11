/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::mt19937 rd(std::chrono::system_clock::now().time_since_epoch().count());

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<int> a(n+2),b(m+2);
    i64 sa=0,sb=0;
    for(int i=1;i<=n;i++) std::cin>>a[i],sa+=a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i],sb+=b[i];
    i64 sum=sa*sb;

    std::unordered_set<i64> qa,qb;

    qa.reserve(1024+rd()%1024);
    qa.max_load_factor(0.25); 
    qb.reserve(1024+rd()%1024);
    qb.max_load_factor(0.25); 

    for(int i=1;i<=n;i++) qa.insert(sa-a[i]);
    for(int i=1;i<=m;i++) qb.insert(sb-b[i]);

    auto check=[&](i64 l,i64 r,i64 x)->bool{
        if(l*r!=x) return 0;
        return ((qa.count(l) and qb.count(r)) or (qb.count(l) and qa.count(r)));
    };

    while(q--){
        int x;
        std::cin>>x;
        bool flag=0;
        for(int i=1;1ll*i*i<=std::abs(x);i++){
            if(x%i) continue;
            i64 l=i,r=std::abs(x)/i;
            flag |= check(l,r,x) | check(-l,r,x) | check(l,-r,x) | check(-l,-r,x);
        }

        std::cout<<(flag ? "YES" : "NO")<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
