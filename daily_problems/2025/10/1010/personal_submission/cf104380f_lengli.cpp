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
    int n,L,R;
    std::cin>>n>>L>>R;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;

    int t=std::min(L-1,n-R);
    while(t--) a.pop_back();
    std::sort(all(a));
    std::reverse(all(a));
    i64 res=0;
    for(int i=0;i<R-L+1;i++){
        res+=a[i];
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
