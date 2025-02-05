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
    std::array<int,3> pt,my;
    std::cin>>pt[0]>>pt[1]>>pt[2];
    std::cin>>my[0]>>my[1]>>my[2];
    std::vector<int> a(6);
    for(auto &x:a) std::cin>>x;
    int res=0;
    if(pt[1]<0) res+=a[0];
    if(pt[1]>my[1]) res+=a[1];
    if(pt[2]<0) res+=a[2];
    if(pt[2]>my[2]) res+=a[3];
    if(pt[0]<0) res+=a[4];
    if(pt[0]>my[0]) res+=a[5];
    std::cout<<res<<"\n";
} 

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
