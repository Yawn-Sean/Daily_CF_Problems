/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> pt(k);
    for(int i=2,j=0;i<=n;i++,j++){
        pt[j%k].pb(i);
    }
    int res=(n-1)/k*2;
    if((n-1)%k==1) res++;
    else if((n-1)%k) res+=2;
    std::cout<<res<<"\n";
    for(int i=0;i<k;i++){
        std::cout<<1<<" "<<pt[i][0]<<"\n";
        for(int j=1;j<pt[i].size();j++){
            std::cout<<pt[i][j-1]<<" "<<pt[i][j]<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
