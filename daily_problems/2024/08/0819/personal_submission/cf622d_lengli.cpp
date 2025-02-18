/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> res(n*2+2,0);
    int ll=1,lr=n,rl=n+1,rr=n*2-1;
    for(int i=1;i<n;i++){
        if(i&1) res[ll]=res[lr]=i,ll++,lr--;
        else res[rl]=res[rr]=i,rl++,rr--;
    }
    for(int i=1;i<=n*2;i++){
        if(!res[i]) std::cout<<n<<" ";
        else std::cout<<res[i]<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
