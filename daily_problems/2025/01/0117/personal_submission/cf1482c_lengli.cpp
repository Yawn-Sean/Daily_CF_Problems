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
    std::vector<std::vector<int>> q(m);
    for(int i=0;i<m;i++){
        int k;
        std::cin>>k;
        for(int j=0;j<k;j++){
            int x;
            std::cin>>x;
            q[i].pb(x);
        }
    }
    std::vector<int> use(n+2);
    int limit=(m+1)/2;
    std::vector<int> res;
    for(auto a:q){
        sort(all(a),[&](auto l,auto r){
            return use[l]<use[r];
        });
        use[a[0]]++;
        res.pb(a[0]);
        if(use[a[0]]>limit){
            std::cout<<"NO"<<"\n";
            return;
        }
    }
    std::cout<<"YES"<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
