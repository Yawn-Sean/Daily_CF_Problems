/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int f[4][4][202][202];
std::array<int,4> fa[4][4][202][202];
int st[4][4][202][202];

int dfs(int x,int y,int z,int w){
    if(st[x][y][z][w]) return f[x][y][z][w];
    int flag=0;

    if(x+y==5){
        int nd=15;
        if(x==3){
            if(z>=nd and x>=1){
                for(int j=0;j<=nd-2;j++){
                    if(w>=j) {
                        int v=dfs(x-1,y,z-nd,w-j);
                        if(v) fa[x][y][z][w]={x-1,y,z-nd,w-j};
                        flag|=v;
                    }
                }
                for(int j=nd;j<=200;j++){
                    if(z-j>=0 and w-(j-2)>=0){
                        int v=dfs(x-1,y,z-j,w-(j-2));
                        if(v) fa[x][y][z][w]={x-1,y,z-j,w-(j-2)};
                        flag|=v;
                    }
                }
            }
        }else if(y==3){
            if(w>=nd and y>=1){
                for(int j=0;j<=nd-2;j++){
                    if(z>=j){
                        int v=dfs(x,y-1,z-j,w-nd);
                        if(v) fa[x][y][z][w]={x,y-1,z-j,w-nd};
                        flag|=v;
                    }
                }
                for(int j=nd;j<=200;j++){
                    if(w-j>=0 and z-(j+2)>=0){
                        int v=dfs(x,y-1,z-(j-2),w-j);
                        if(v) fa[x][y][z][w]={x,y-1,z-(j-2),w-j};
                        flag|=v;
                    }
                }
            }
        }
    }else{
        int nd=25;
        if(z>=nd and x>=1){
            for(int j=0;j<=nd-2;j++){
                if(w>=j and y!=3) {
                    int v=dfs(x-1,y,z-nd,w-j);
                    if(v) fa[x][y][z][w]={x-1,y,z-nd,w-j};
                    flag|=v;
                }
            }
            for(int j=nd;j<=200;j++){
                if(z-j>=0 and w-(j-2)>=0 and y!=3){
                    int v=dfs(x-1,y,z-j,w-(j-2));
                    if(v) fa[x][y][z][w]={x-1,y,z-j,w-(j-2)};
                    flag|=v;
                }
            }
        }
        if(w>=nd and y>=1){
            for(int j=0;j<=nd-2;j++){
                if(z>=j and x!=3){
                    int v=dfs(x,y-1,z-j,w-nd);
                    if(v) fa[x][y][z][w]={x,y-1,z-j,w-nd};
                    flag|=v;
                }
            }
            for(int j=nd;j<=200;j++){
                if(w-j>=0 and z-(j-2)>=0 and x!=3){
                    int v=dfs(x,y-1,z-(j-2),w-j);
                    if(v) fa[x][y][z][w]={x,y-1,z-(j-2),w-j};
                    flag|=v;
                }
            }
        }
    }

    st[x][y][z][w]=1;
    return f[x][y][z][w]=flag;
}

void solve(){
    f[0][0][0][0]=1;
    st[0][0][0][0]=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<=200;k++){
                for(int l=0;l<=200;l++){
                    fa[i][j][k][l]={-1,-1,-1,-1};
                    if(!st[i][j][k][l]){
                        dfs(i,j,k,l);
                    }
                }
            }
        }
    }

    int q;
    std::cin>>q;
    while(q--){
        int l,r;
        std::cin>>l>>r;
        int rl=-1,rr=-1;
        for(int j=0;j<3;j++){
            if(f[3][j][l][r]){
                rl=3,rr=j;
                break;
            }
        }
        if(rl==-1){
            for(int j=2;j>=0;j--){
                if(f[j][3][l][r]){
                    rl=j,rr=3;
                    break;
                }
            }
        }
        if(rl==-1){
            std::cout<<"Impossible"<<"\n";
            continue;
        }

        int dl=rl,dr=rr;

        std::cout<<dl<<":"<<dr<<"\n";

        std::vector<std::array<int,2>> res;

        while(dl>0 or dr>0){
            auto [x,y,z,w]=fa[dl][dr][l][r];
            res.pb({l-z,r-w});
            l=z,r=w;
            dl=x,dr=y;
        }
        reverse(all(res)); 


        for(auto [x,y]:res) std::cout<<x<<":"<<y<<" ";
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
