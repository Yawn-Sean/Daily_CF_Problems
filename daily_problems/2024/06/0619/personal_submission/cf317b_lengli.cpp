/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=1010;

void solve(){
    int k,q;
    std::cin>>k>>q;
    int dx=500,dy=500;
    std::vector<std::vector<int>> a(N,std::vector<int>(N,0));
    a[dx][dy]=k;
    auto dfs=[&](auto self,int xx,int yy)->void{
        if(a[xx][yy]<4) return;
        int t=a[xx][yy]/4;
        a[xx][yy]%=4;
        a[xx-1][yy]+=t;
        a[xx][yy-1]+=t;
        a[xx+1][yy]+=t;
        a[xx][yy+1]+=t;
        self(self,xx-1,yy);
        self(self,xx,yy-1);
        self(self,xx,yy+1);
        self(self,xx+1,yy);
    };

    dfs(dfs,dx,dy);

    while(q--){
        int x,y;
        std::cin>>x>>y;
        x+=dx,y+=dy;
        if(x<0 or x>=N or y<0 or y>=N) std::cout<<0<<"\n";
        else std::cout<<a[x][y]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
