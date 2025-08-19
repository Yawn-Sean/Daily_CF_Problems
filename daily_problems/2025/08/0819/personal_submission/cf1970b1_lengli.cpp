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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++){
        std::cout<<i<<" "<<i<<"\n";
    }
    for(int i=1;i<=n;i++){
        if(i-a[i]/2>=1) std::cout<<i-a[i]/2<<" "; 
        std::cout<<i+a[i]/2<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
