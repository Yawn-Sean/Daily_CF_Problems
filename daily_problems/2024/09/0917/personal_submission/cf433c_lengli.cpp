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
    std::vector<int> a(m+2);
    long long res=0;
    for(int i=1;i<=m;i++){
        std::cin>>a[i];
        if(i>1) res+=std::abs(a[i]-a[i-1]);
    }
    if(m==1){
        std::cout<<0<<"\n";
        return;
    }
    std::vector<std::vector<int>> q(n+2);
    a[0]=a[1],a[m+1]=a[m];
    for(int i=1;i<m;i++) {
        if(a[i]!=a[i+1]){
            q[a[i]].pb(a[i+1]);
            q[a[i+1]].pb(a[i]);
        }
    }
    long long sum=res;
    for(int i=1;i<=n;i++){
        long long ans=0;
        if(q[i].empty()) continue;
        sort(all(q[i]));
        for(auto x:q[i]) ans+=std::abs(i-x);
        for(int j=((int)q[i].size()-1)/2;j<=std::min(((int)q[i].size()-1)/2+1,(int)q[i].size()-1);j++){
            int c=q[i][j];
            long long nans=0;
            for(auto x:q[i]) nans+=std::abs(c-x);
            long long dlt=nans-ans;
            res=std::min(res,sum+dlt);
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
