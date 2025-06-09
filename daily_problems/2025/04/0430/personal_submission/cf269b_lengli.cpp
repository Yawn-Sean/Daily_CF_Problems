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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n);
    for(auto &x:a){
        std::cin>>x;
        std::string s;
        std::cin>>s;
    }
    std::vector<int> f(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]) f[i]=std::max(f[i],f[j]+1);
        }
    }
    int res=n-*std::max_element(all(f));
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
