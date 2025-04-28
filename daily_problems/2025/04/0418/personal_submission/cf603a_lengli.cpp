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
    std::string s;
    std::cin>>n>>s;

    int res=1,same=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) res++;
        else same++;
    }
    if(same>=2) res+=2;
    else if(same==1) res++;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
