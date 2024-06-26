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
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n);
    int res=0;
    std::vector<int> q;
    for(auto &[x,y]:a){
        std::cin>>x>>y;
        res-=x,res+=n*y;
        q.pb(x-y);
    }
    sort(all(q));
    for(int i=n,j=0;j<n;j++,i--){
        res+=i*q[j];
    }
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
