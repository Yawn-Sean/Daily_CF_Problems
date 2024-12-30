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
    std::vector<int> a(n+2);
    std::vector<std::vector<int>> q(m+2);
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        q[a[i]%m].pb(i);
    }
    long long k=n/m,res=0;
    for(int tt=0;tt<=4;tt++){
        for(int i=0,j=0;i<m*2;i++){
            if(q[i%m].size()<=k) continue;
            while(q[i%m].size()>k){
                auto t=q[i%m].back();
                q[i%m].pop_back();
                while(j<m*2 and (j<=i or q[j%m].size()>=k)) j++;
                q[j%m].pb(t);
                a[t]+=j-i;
                res+=j-i;
            }
        }
    }
    std::cout<<res<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
    

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
