/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=100010;

void solve(){
    std::vector<int> eg[N];
    std::vector<int> la(N,0);
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i) eg[j].pb(i);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        std::cin>>x>>y;
        int res=0;
        for(auto c:eg[x]){
            res+=(la[c] ? la[c]<i-y ? 1 : 0 : 1);
            la[c]=i;
        }
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
