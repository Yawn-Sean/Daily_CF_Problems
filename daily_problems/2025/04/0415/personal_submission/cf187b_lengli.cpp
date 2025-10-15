/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=61;
constexpr int inf=2e9;
int n,m,q;

int dis[N][N][N];
int d[N][N][N];

void solve(){
    std::cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++){
                std::cin>>dis[i][j][k];
            }
            
    for(int id=1;id<=m;id++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[id][i][j]=std::min(dis[id][i][j],dis[id][i][k]+dis[id][k][j]);
                }
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<N;k++){
                d[i][j][k]=inf;
            }
        }
    }

    for(int k=0;k<N;k++){
        if(k==0){
            for(int id=1;id<=m;id++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        d[i][j][k]=std::min(d[i][j][k],dis[id][i][j]);
                    }
                }
            }
        }else{
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    d[i][j][k]=std::min(d[i][j][k],d[i][j][k-1]);
                }
            for(int t=1;t<=n;t++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        d[i][j][k]=std::min(d[i][j][k],d[i][t][k-1]+d[t][j][0]);
                    }
                }
            }
        }
    }

    while(q--){
        int s,t,k;
        std::cin>>s>>t>>k;
        k=std::min(k,N-1);
        std::cout<<d[s][t][k]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
