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
    std::vector<std::vector<int>> q(n+2);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        q[i].resize(x,0);
        for(int j=0;j<x;j++){
            std::cin>>q[i][j];
        }
        std::sort(all(q[i]));
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<q[i].size();j++){
            int ne=(i+1)%n;
            int la=(i+n-1)%n;
            int a=std::upper_bound(all(q[ne]),q[i][j])-std::lower_bound(all(q[ne]),q[i][j-1]);
            int b=std::upper_bound(all(q[la]),q[i][j])-std::lower_bound(all(q[la]),q[i][j-1]);
            res+=(a!=b);
        }
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
