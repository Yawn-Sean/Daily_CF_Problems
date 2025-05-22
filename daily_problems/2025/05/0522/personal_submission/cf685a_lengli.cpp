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

void solve(){
    int n,m;
    std::cin>>n>>m;
    n--,m--;
    int lenx=0,leny=0;

    auto get=[&](int &res,int x){
        while(x){
            res++;
            x/=7;
        }
        res=std::max(res,1);
        return res;
    };
    get(lenx,n),get(leny,m);

    if(lenx+leny>7){
        std::cout<<0<<"\n";
        return;
    }

    int res=0;

    auto check=[&](int l,int r){
        std::set<int> s;
        for(int i=0;i<lenx;i++){
            if(s.count(l%7)) return 0;
            s.insert(l%7);
            l/=7;
        }
        for(int i=0;i<leny;i++){
            if(s.count(r%7)) return 0;
            s.insert(r%7);
            r/=7;
        }
        return 1;
    };

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(check(i,j)) res++;
        }
    }

    std::cout<<res<<"\n";
}

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}
