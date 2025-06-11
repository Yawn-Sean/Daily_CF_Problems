/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> a(n+2,std::vector<int> (m+2));
    std::vector<std::vector<int>> b(n+2,std::vector<int> (m+2));
    std::vector<std::vector<int>> f(n+2,std::vector<int> (m+2));
    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            a[i][j]=c=='1';
            b[i][j]=a[i][j];
            f[i][j]=a[i][j];
            g[i][j]=a[i][j];
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]+=f[i][j-1];
            g[i][j]+=g[i-1][j];
            b[i][j]+=b[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]+=b[i-1][j];
        }
    }

    auto geti=[&](int x,int y,int i){
        return -2*i+f[x][i]+f[y][i]-g[y-1][i]+g[x][i]-b[y-1][i]+b[x][i];
    };
    auto getj=[&](int x,int y,int j){
        return 2*j-2-f[x][j-1]-f[y][j-1]+2*y-2*x-2-g[y-1][j]+g[x][j]+b[y-1][j-1]-b[x][j-1];
    };

    int res=1e9;
    
    for(int x=1;x<=n;x++){
        for(int y=x+4;y<=n;y++){
            int pre=geti(x,y,1),i=1;
            for(int j=1;j<=m;j++){
                while(j-i+1>4){
                    i++;
                    pre=std::min(pre,geti(x,y,i));
                }
                if(j-i+1>=4){
                    int ans=getj(x,y,j)+pre;
                    res=std::min(res,ans);
                }
            }
        }
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
