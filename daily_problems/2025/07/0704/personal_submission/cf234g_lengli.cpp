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
    std::vector<std::vector<int>> res;
    int mx=0;
    for(int i=0;i<32;i++){
        std::vector<int> q;
        for(int v=1;v<=n;v++){
            if(v>>i&1) q.pb(v);
        }
        if(q.empty()){
            mx=i-1;
            break;
        }
        res.pb(q);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i>>mx&1) cnt++;
    }
    if(cnt<=1) res.pop_back();
    std::cout<<res.size()<<"\n";
    for(auto x:res){
        std::cout<<x.size()<<" ";
        for(auto y:x) std::cout<<y<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
