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
    std::string s;
    std::cin>>s;
    std::set<char> set;
    for(auto x:s) set.insert(x);
    if(set.size()==1){
        std::cout<<"NO"<<"\n";
        return;
    }
    if(n==3 and set.size()==3){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
