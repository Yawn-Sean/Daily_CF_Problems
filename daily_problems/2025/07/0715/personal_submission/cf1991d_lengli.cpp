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
    std::vector<std::vector<int>> q={
        {1},{1,2},{1,2,2},{1,2,2,3},
        {1,2,2,3,3},{1,2,2,3,3,4}
    };
    if(n<=q.size()){
        std::cout<<q[n-1].back()<<"\n";
        for(auto x:q[n-1]) std::cout<<x<<" ";
        std::cout<<"\n";
        return;
    }
    std::cout<<4<<"\n";
    for(int i=1;i<=n;i++){
        std::cout<<(i%4)+1<<" ";
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
