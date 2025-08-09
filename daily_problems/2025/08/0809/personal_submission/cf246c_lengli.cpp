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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::sort(a.begin()+1,a.end()-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            std::cout<<i<<" ";
            for(int t=n;t>n-i+1;t--){
                std::cout<<a[t]<<" ";
            }
            std::cout<<a[j]<<"\n";
            if(!(--k)) return;
        }
    }
    return;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
