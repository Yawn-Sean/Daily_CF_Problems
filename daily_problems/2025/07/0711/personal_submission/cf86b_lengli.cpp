/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2,'#'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
        }
    }

    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]!='.') continue;

            bool flag=0;
            for(int k=0;k<4 and !flag;k++){
                int x=i+dx[k],y=j+dy[k];
                if(g[x][y]=='.'){
                    flag=1;
                    g[i][j]=g[x][y]=(i%3)*3+j%3+'0';
                }
            }
            for(int k=0;k<4 and !flag;k++){
                int x=i+dx[k],y=j+dy[k];
                if(g[x][y]!='#'){
                    flag=1;
                    g[i][j]=g[x][y];
                }
            }
            if(!flag){
                std::cout<<"-1"<<"\n";
                return;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cout<<g[i][j];
        }
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
