/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100,inf=1e9;

int n;
int sx,sy,sz;
int f[N][N][N];
int st[N][N][N];
std::array<int,3> fa[N][N][N];
char g[N][N];

void solve(){
    std::cin>>n>>sx>>sy>>sz;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++){
                f[i][j][k]=inf;
                fa[i][j][k]={0,0,0};
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) std::cin>>g[i][j];
    std::queue<std::array<int,4>> q;
    q.push({0,sx,sy,sz});
    f[sx][sy][sz]=0;

    while(q.size()){
        auto [d,x,y,z]=q.front();
        q.pop();
        if(st[x][y][z]) continue;
        st[x][y][z]=d;
        for(int i=1,c=g[y][z];i<=n;i++){
            if(g[x][i]!=c or i==y or i==z) continue;
            if(f[i][y][z]>d+1){
                f[i][y][z]=d+1;
                fa[i][y][z]={x,y,z};
                q.push({d+1,i,y,z});
            }
        }
        for(int i=1,c=g[x][z];i<=n;i++){
            if(g[y][i]!=c or i==x or i==z) continue;
            if(f[x][i][z]>d+1){
                f[x][i][z]=d+1;
                fa[x][i][z]={x,y,z};
                q.push({d+1,x,i,z});
            }
        }
        for(int i=1,c=g[x][y];i<=n;i++){
            if(g[z][i]!=c or i==x or i==y) continue;
            if(f[x][y][i]>d+1){
                f[x][y][i]=d+1;
                fa[x][y][i]={x,y,z};
                q.push({d+1,x,y,i});
            }
        }
    }
    std::vector<int> a={1,2,3},res;
    int mi=inf;
    do{
        if(f[a[0]][a[1]][a[2]]<mi){
            res=a;
            mi=f[a[0]][a[1]][a[2]];
        }
    }while(std::next_permutation(all(a)));
    if(mi==inf){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<std::array<int,2>> ans;
    int x=res[0],y=res[1],z=res[2];
    while(1){
        if(x==sx and y==sy and z==sz) break;
        auto [nx,ny,nz]=fa[x][y][z];
        if(nx!=x) ans.pb({nx,x});
        if(ny!=y) ans.pb({ny,y});
        if(nz!=z) ans.pb({nz,z});
        std::tie(x,y,z)=std::tie(nx,ny,nz);
    }  
    reverse(all(ans));
    std::cout<<ans.size()<<"\n";
    for(auto [x,y]:ans) std::cout<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
