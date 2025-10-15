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
    std::priority_queue<i64,std::vector<i64>,std::greater<i64>> s;
    for(int i=1;i<=m;i++){
        s.push(1);
    }
    for(int i=1;i<=n;i++){
        i64 x,len;
        std::cin>>x>>len;
        auto it=s.top();
        s.pop();
        i64 ed=std::max(it,x)+len;
        s.push(ed);
        std::cout<<ed<<"\n";
    } 
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
