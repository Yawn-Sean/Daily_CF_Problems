/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> a(n);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[i]={x,i};
    }
    sort(all(a));
    std::vector<int> res(n);
    for(int j=0;j<n;j++){
        res[a[j][1]]=(j&1);
    }
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
