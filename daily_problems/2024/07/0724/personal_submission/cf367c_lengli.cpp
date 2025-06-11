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
    std::vector<int> c(m);
    for(int i=0;i<m;i++){
        std::cin>>c[i]>>c[i];
    }
    sort(all(c),std::greater<>());

    int res=0,ans=0;
    long long len=1;
    for(int i=1;i<=m;i++){
        ans+=c[i-1];
        len+=i-1;
        if(i&1){
            if(len<=n) res=ans;
        }else{
            int k=i/2-1;
            if(len+k<=n) res=ans;
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
