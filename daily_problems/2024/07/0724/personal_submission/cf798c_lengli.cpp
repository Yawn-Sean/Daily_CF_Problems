/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    int d=0;
    for(int i=1;i<=n;i++) std::cin>>a[i],d=std::gcd(d,a[i]);
    if(d!=1){
        std::cout<<"YES"<<"\n";
        std::cout<<0<<"\n";
    }else{
        int res=0;
        for(int i=1;i<=n;i++){
            if(a[i]&1){
                bool r=i<n and a[i+1]&1;
                if(r) res++,i++;
                else res+=2;
            }
        }
        std::cout<<"YES"<<"\n";
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
