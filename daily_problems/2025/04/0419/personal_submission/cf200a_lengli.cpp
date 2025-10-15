/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=2110,inf=1e6;

int n,m,k,x,y;
int p,q;
int res;

int D[N][N],U[N][N];
int findD(int x,int y){
    if(D[x][y]==x)  return x;
    return D[x][y]=findD(D[x][y],y);
}
int findU(int x,int y){
    if(U[x][y]==x)  return x;
    return U[x][y]=findU(U[x][y],y);
}

void op(int xx,int yy){
    if(xx<1 or xx>n or yy<1 or yy>m) return;
    int d=std::abs(xx-x)+std::abs(yy-y);
    if(d<res or (d==res and xx<p) or (d==res and xx==p and yy<q)){
        res=d;
        p=xx,q=yy;
    }
}   

void solve(){
    std::cin>>n>>m>>k;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            D[i][j]=i,U[i][j]=i;
        }
    }
    for(int i=1;i<=k;i++){
        std::cin>>x>>y;
        res=inf;
        for(int d=0;d<=res;d++){
            if(y-d>=1){
                op(findU(x,y-d),y-d);
                op(findD(x,y-d),y-d);
            }
            if(y+d<=m){
                op(findU(x,y+d),y+d);
                op(findD(x,y+d),y+d);
            }
        }
        U[p][q]=p-1;
        D[p][q]=p+1;
        std::cout<<p<<" "<<q<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
