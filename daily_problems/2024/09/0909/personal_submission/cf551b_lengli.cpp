/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string s,a,b;
    std::cin>>s>>a>>b;
    std::map<char,int> q[3];
    for(auto x:s) q[0][x]++;
    for(auto x:a) q[1][x]++;
    for(auto x:b) q[2][x]++;
    int l=0,r=0;
    for(int i=0;i<=s.size();i++){
        bool flag=1;
        for(auto [c,cnt]:q[1]){
            if(q[0][c]<1ll*i*cnt) flag=0;
        }
        if(!flag) break;
        long long k=1e9;
        for(auto [c,cnt]:q[2]){
            auto hv=q[0][c]-1ll*i*q[1][c];
            k=std::min(k,hv/cnt);
        }
        if(i+k>l+r) l=i,r=k;
    }
    for(int i=0;i<l;i++) std::cout<<a;
    for(int i=0;i<r;i++) std::cout<<b;
    for(auto [c,cnt]:q[0]){
        cnt-=l*q[1][c]+r*q[2][c];
        for(int i=0;i<cnt;i++) std::cout<<c;
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
