/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
 
#define int long long
 
void solve(){
    std::string s;
    std::cin>>s;
    long long res=0,cnt=0;
    for(auto x:s){
        if(x=='M') cnt++;
        else if(cnt) res+=(cnt>res) ? cnt-res : 1;
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
