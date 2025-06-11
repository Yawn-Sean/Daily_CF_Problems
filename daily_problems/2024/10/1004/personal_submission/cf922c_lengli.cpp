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
    int n,k;
    std::cin>>n>>k;
    bool flag=1;
    for(int i=1;i<=std::min(50ll,k);i++){
        if(n%i!=i-1){
            flag=0;
            break;
        }
    }
    std::cout<<(flag ? "Yes" : "No")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
