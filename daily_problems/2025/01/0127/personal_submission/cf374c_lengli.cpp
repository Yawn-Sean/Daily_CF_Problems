/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1010;

int n,m;
char g[N][N];
bool isin[N][N];
bool st[N][N];
int len[N][N];
std::map<char,char> ne;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool flag=1;

void dfs(int x,int y){
    if(!flag) return;
    if(isin[x][y]){
        flag=0;
        return;
    }
    if(st[x][y]) return;
    isin[x][y]=1;
    st[x][y]=1;
    int mx=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1 or nx>n or ny<1 or ny>m) continue;
        if(g[nx][ny]!=ne[g[x][y]]) continue;
        dfs(nx,ny);
        mx=std::max(mx,len[nx][ny]);
    }
    isin[x][y]=0;
    len[x][y]=mx+1;
}

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) std::cin>>g[i][j];
    ne['D']='I',ne['I']='M',ne['M']='A',ne['A']='D';

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j]) continue;
            if(g[i][j]=='D'){
                dfs(i,j);
            }
        }
    }

    if(!flag){
        std::cout<<"Poor Inna!"<<"\n";
        return;
    }

    int res=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            res=std::max(res,len[i][j]/4);
        }

    if(!res) std::cout<<"Poor Dima!"<<"\n";
    else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
