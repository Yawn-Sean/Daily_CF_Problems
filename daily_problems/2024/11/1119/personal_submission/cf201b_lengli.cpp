/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> a(n,std::vector<int> (m,0));
    std::vector<i64> x(n,0),y(m,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            std::cin>>a[i][j];
            x[i]+=a[i][j];
            y[j]+=a[i][j];
        }
    std::vector<i64> sumx(n,0),sumy(m,0);
    for(int i=0;i<n;i++){
        for(int t=i-1,len=2;t>=0;t--,len+=4) sumx[i]+=1ll*x[t]*len*len;
        for(int t=i,len=2;t<n;t++,len+=4) sumx[i]+=1ll*x[t]*len*len;
    }
    for(int i=0;i<m;i++){
        for(int t=i-1,len=2;t>=0;t--,len+=4) sumy[i]+=1ll*y[t]*len*len;
        for(int t=i,len=2;t<m;t++,len+=4) sumy[i]+=1ll*y[t]*len*len;
    }

    i64 res=1e18;
    std::array<int,2> idx;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            i64 ans=sumx[i]+sumy[j];
            if(ans<res){
                res=ans;
                idx={i,j};
            }
        }
    }

    std::cout<<res<<"\n";
    std::cout<<idx[0]<<" "<<idx[1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
