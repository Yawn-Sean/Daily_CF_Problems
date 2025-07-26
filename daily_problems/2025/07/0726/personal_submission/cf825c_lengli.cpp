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
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    int res=0;
    for(int i=0;i<n;i++){
        while(a[i]>2*k){
            res++;
            k*=2;
        }
        k=std::max(k,a[i]);
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
