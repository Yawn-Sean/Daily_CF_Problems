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
    std::vector<std::array<int,2>> q(3);
    for(auto &[x,y]:q){
        std::cin>>x>>y;
    }
    int res=3;
    auto check=[&](){
        sort(all(q),[&](auto l,auto r){
            return l[1]<r[1];
        });
        if(q[0][0]==q[1][0] and q[1][0]==q[2][0]) res=std::min(res,1);
        if(q[0][0]==q[1][0] and (q[0][1]==q[2][1] or q[1][1]==q[2][1])) res=std::min(res,2);
        if(q[0][0]==q[2][0] and (q[0][1]==q[1][1] or q[2][1]==q[1][1])) res=std::min(res,2);
        if(q[1][0]==q[2][0] and (q[1][1]==q[0][1] or q[2][1]==q[0][1])) res=std::min(res,2);
        if(q[0][0]==q[1][0]) res=std::min(res,2);
        if(q[1][0]==q[2][0]) res=std::min(res,2);
    };
    check();
    for(auto &[x,y]:q) std::swap(x,y);
    check();
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
