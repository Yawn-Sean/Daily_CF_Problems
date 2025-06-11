/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=100010;
constexpr long long inf=1e18;

using i64=long long;

int n,m;
std::vector<std::array<int,3>> q[N];
int a[N];
i64 ed[N];
i64 f[N][102];
std::array<int,2> la[N][102];
int use[N][102];

void clear(){
    for(int i=1;i<=n;i++) q[i].clear(),ed[i]=-1;
}

void solve(){
    std::cin>>n>>m;

    clear();

    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++){
        int e,t,p;
        std::cin>>e>>t>>p;
        q[e].pb({t,p,i});
    }

    std::vector<std::array<int,4>> res;

    for(int idx=1;idx<=n;idx++){
        int k=q[idx].size();
        for(int ii=0;ii<=k;ii++)
            for(int jj=0;jj<=100;jj++) {
                f[ii][jj]=inf;
                la[ii][jj]={-1,-1};
                use[ii][jj]=-1;
            }
        f[0][0]=0;

        for(int i=1;i<=k;i++){
            auto [t,p,id]=q[idx][i-1];
            for(int j=100;j>=0;j--) {
                f[i][j]=f[i-1][j];
                la[i][j]=la[i-1][j];
                use[i][j]=use[i-1][j];
            }
            for(int j=0;j<=100;j++){
                int np=std::min(j+p,100);
                if(f[i][np]>f[i-1][j]+t){
                    f[i][np]=f[i-1][j]+t;
                    la[i][np]={i-1,j};
                    use[i][np]=i;
                }
            }
        }
        if(f[k][100]==inf){
            std::cout<<"-1"<<"\n";
            return;
        }
        int sx=k,sy=100;
        while(sy>0){
            int ni=use[sx][sy]-1;
            auto [t,p,id]=q[idx][ni];
            res.pb({idx,t,p,id});
            int nsx=la[sx][sy][0],nsy=la[sx][sy][1];
            sx=nsx,sy=nsy;
        }
    }

    for(auto [idx,t,p,id]:res){
        if(ed[idx]==-1) ed[idx]=ed[idx-1]+t;
        else ed[idx]+=t;
    }
    for(int i=1;i<=n;i++){
        if(ed[i]>a[i]){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto [idx,t,p,id]:res) std::cout<<id<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
