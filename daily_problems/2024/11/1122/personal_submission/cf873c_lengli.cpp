/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> a(n+2,std::vector<int> (m+2,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) std::cin>>a[i][j];

    int res=0,cnt=0;

    for(int j=1;j<=m;j++){
        std::vector<int> q(n+2,0);
        for(int i=1;i<=n;i++) q[i]=a[i][j];
        for(int i=1;i<=n;i++) q[i]+=q[i-1];
        int ans=0,tmp=0;
        for(int i=k;i<=n;i++){
            int t=q[i]-q[i-k];
            if(t>ans){
                ans=t;
                tmp=q[i-k];
            }
        }
        res+=ans,cnt+=tmp;
    }
    std::cout<<res<<" "<<cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
