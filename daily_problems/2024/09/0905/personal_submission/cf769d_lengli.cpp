/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
 
#define int long long
 
void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> q;
    for(int i=0;i<(1<<14);i++){
        int t=__builtin_popcount(i);
        if(t==k) q.pb(i);
    }
    std::vector<int> cnt(10010,0);
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        cnt[x]++;
    }
    long long res=0;
    for(int i=0;i<=10000;i++){
        if(cnt[i]){
            for(auto x:q){
                int v=i;
                for(int j=0;j<14;j++){
                    if(x>>j&1) v^=(1<<j);
                }
                if(v<i) res+=1ll*cnt[i]*cnt[v];
            }
        }
        if(!k) res+=1ll*(cnt[i]-1)*cnt[i]/2;
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
