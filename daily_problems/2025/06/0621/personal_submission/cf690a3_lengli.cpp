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
    int n,r;
    std::cin>>n>>r;
    r--;
    int sum=0;
    for(int i=1;i<n;i++){
        int x;
        std::cin>>x;
        sum=(sum+x)%n;
    }
    int v=(r-sum+n)%n;
    if(!v) v=n; 
    std::cout<<v<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
