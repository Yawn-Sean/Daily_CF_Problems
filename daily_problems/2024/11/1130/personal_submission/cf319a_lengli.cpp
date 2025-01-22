/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    Mint res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            res+=Mint(2).pow(i-1)*Mint(4).pow(n-i);
        }
    }
    std::cout<<res/2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
