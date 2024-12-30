/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=2e9;

void solve(){
    int n,m,k,q;
    std::cin>>n>>m>>k>>q;
    std::vector<std::vector<int>> a(n,std::vector<int> (m,inf));
    for(int i=1;i<=q;i++){
        int x,y,t;
        std::cin>>x>>y>>t;
        x--,y--;
        a[x][y]=t;
    }
    std::vector<std::vector<int>> b(n,std::vector<int> (m,0));
    std::vector<std::vector<int>> c(n,std::vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j+k-1<m;j++){
            for(int l=j;l<j+k;l++){
                b[i][j]=std::max(b[i][j],a[i][l]);
            }
        }
    }
    for(int j=0;j<m;j++){
        for(int i=0;i+k-1<n;i++){
            for(int l=i;l<i+k;l++){
                c[i][j]=std::max(c[i][j],b[l][j]);
            }
        }
    }
    int res=inf;
    for(int i=0;i+k-1<n;i++)
        for(int j=0;j+k-1<m;j++) res=std::min(res,c[i][j]);
    if(res==inf) res=-1;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
