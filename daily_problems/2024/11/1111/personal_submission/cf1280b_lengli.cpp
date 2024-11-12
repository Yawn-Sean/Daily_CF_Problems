/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::vector<std::vector<char>> rotate(std::vector<std::vector<char>> &grid){
    int n=grid.size(),m=grid[0].size();
    std::vector<std::vector<char>> res(m,std::vector<char> (n));
    for(int i=0,jj=n-1;i<n;i++,jj--){
        for(int j=0,ii=0;j<m;j++,ii++){
            res[ii][jj]=grid[i][j];
        }
    }
    return res;
};


void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n,std::vector<char> (m));
    int cntA=0,cntP=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            std::cin>>g[i][j];
            if(g[i][j]=='A') cntA++;
            else cntP++;
        }
    if(cntA==n*m){
        std::cout<<0<<"\n";
        return;
    }
    if(cntP==n*m){
        std::cout<<"MORTAL"<<"\n";
        return;
    }

    int res=1000000000;

    auto check=[&](std::vector<std::vector<char>> &a){
        int nn=a.size(),mm=a[0].size();
        for(int i=0;i<nn;i++){
            int cnt=0;
            for(int j=0;j<mm;j++) if(a[i][j]=='A') cnt++;
            if(cnt==mm){
                if(i==0) res=std::min(res,1);
                else res=std::min(res,2);
            }
            if(cnt){
                if(i==0) res=std::min(res,3);
                else res=std::min(res,4);
            }
        }
        if(a[0][mm-1]=='A' or a[0][0]=='A') res=std::min(res,2);
    };

    for(int i=0;i<4;i++){
        check(g);
        g=rotate(g);
    }

    std::cout<<res<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
