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
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;

    i64 cm=1;
    sort(all(a));
    for(auto x:a){
        cm=std::lcm(cm,(i64)x);
        if(cm>a.back()){
            std::cout<<n<<"\n";
            return;
        }
    }
    std::set<int> s;
    for(auto x:a) s.insert(x);
    i64 res=0;

    auto cal=[&](int x){
        i64 d=1,len=0;
        for(auto v:a){
            if(x%v==0) d=std::lcm(d,v),len++;
        }
        if(!s.count(d) and d==x) return len;
        return 0ll;
    };
    for(i64 i=1;i*i<=cm;i++){
        if(cm%i==0) 
            res=std::max(res,std::max(cal(i),cal(cm/i)));
    }
    std::cout<<res<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
