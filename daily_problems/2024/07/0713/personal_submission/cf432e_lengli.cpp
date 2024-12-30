/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> col(n+2,std::vector<int>(m+2,-1));
    auto check=[&](int x,int y)->int{
        if(col[x][y]!=-1) return col[x][y];
        for(int c=0;c<26;c++){
            bool flag=1;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(col[nx][ny]==c) flag=0;
            }
            if(flag) return c;
        }
        return -1;
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(col[i][j]!=-1) continue;
            auto c=check(i,j);
            int len=0;
            while(check(i,j+len)==c and j+len<=m and i+len<=n) len++;
            len--;
            for(int ii=i;ii<=i+len;ii++)
                for(int jj=j;jj<=j+len;jj++) {
                    col[ii][jj]=c;
                }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) std::cout<<(char)(col[i][j]+'A');
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
