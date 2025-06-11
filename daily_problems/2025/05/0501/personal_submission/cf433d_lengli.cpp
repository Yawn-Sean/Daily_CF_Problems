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

int a[N][N];
int b[N][N];

struct magic{
    std::vector<std::vector<int>> v,s;
    int n,m;
    void init(int _n,int _m) {
        n=_n;m=_m;
        v=std::vector<std::vector<int>>(n+1,std::vector<int>(m+1));
        s=std::vector<std::vector<int>>(n+1,std::vector<int>(m+1));
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++) v[i][j]=a[i][j];
        for(int j=1;j<=m;j++) 
            for(int i=1;i<=n;i++){
                if(v[i][j]) s[i][j]=s[i-1][j]+1;
                else s[i][j]=0;
            }
    }
    void modify(int x,int y) {
        v[x][y]^=1;
        for(int i=1;i<=n;i++){
            if(v[i][y]==1) s[i][y]=s[i-1][y]+1;
            else s[i][y]=0;
        }
    }
    int query(int x,int y) {
        int res=0;
        int l=y,r=y;
        for(int h=n;h>=0;h--) {
            while(l>=1 and s[x][l]>=h) l--;
            while(r<=m and s[x][r]>=h) r++;
            res=std::max(res,h*(r-l-1));
        }
        return res;
    }
}fx[4];

void rotate(int n,int m) {
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) b[i][j]=a[j][m-i+1];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) a[i][j]=b[i][j];
    }
}

int n,m,q;

std::array<int,2> get(int i,int x,int y){
    if(i==0) return {x,y};
    else if(i==1) return {m-y+1,x};
    else if(i==2) return {n-x+1,m-y+1};
    return {y,n-x+1};
}

void solve(){
    std::cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) std::cin>>a[i][j];
    }
    for(int i=0;i<4;i++){
        if(i&1) fx[i].init(m,n),rotate(m,n);
        else fx[i].init(n,m),rotate(n,m);
    }
    while(q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        int res=0;
        for(int i=0;i<4;i++){
            auto [tx,ty]=get(i,x,y);
            if(op==1) fx[i].modify(tx,ty);
            else res=std::max(res,fx[i].query(tx,ty));
        }
        if(op==2) std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
