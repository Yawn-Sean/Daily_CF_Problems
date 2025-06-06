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

    std::vector<std::string> s(n);
    for(auto &x:s){
        std::cin>>x;
        x.erase(x.begin(),x.begin()+4);
        i64 v=0;
        for(auto c:x){
            v*=10;
            v+=c-'0';
        }
        i64 tmp=0;
        i64 b=10;
        for(int i=1;i<x.size();i++){
            tmp+=b;
            b*=10;
        }
        while(tmp+1989>v) v+=b;
        std::cout<<v<<"\n";
    }

}

signed main(){

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
