/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define i128 __int128

void solve(){
    int b,p,limit,m;
    std::cin>>b>>p>>limit>>m;
    std::set<int> s;
    for(int i=0;i<m;i++){
        int x;
        std::cin>>x;
        s.insert(x);
    }

    if(std::abs(b)>limit){
        std::cout<<0<<"\n";
        return;
    }

    i64 ne=1ll*b*p;

    if(std::abs(ne)<=std::abs(b)){
        i64 nne=ne*p;
        i64 res=(std::abs(b)<=limit and !s.count(b));
        if(ne==nne){
            if(s.count(ne)) std::cout<<res<<"\n";
            else std::cout<<"inf"<<"\n";
        }else{
            if(s.count(ne) and s.count(nne)) std::cout<<res<<"\n";
            else std::cout<<"inf"<<"\n";
        }
    }else{
        i64 a=b;
        int res=0;
        for(int i=0;i<32;i++){
            if(std::abs(a)>limit) break;
            if(!s.count(a)) res++;
            a*=p;
        }
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
