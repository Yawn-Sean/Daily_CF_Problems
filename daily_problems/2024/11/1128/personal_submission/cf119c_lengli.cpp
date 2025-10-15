/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=55;

using i64=long long;

std::array<i64,4> work[N];
i64 f[N][N][N*2];
std::array<int,3> fa[N][N][N*2];

void solve(){
    int n,m,D;
    std::cin>>n>>m>>D;
    for(int i=1;i<=m;i++){
        auto &[c,a,b,id]=work[i];
        std::cin>>a>>b>>c;
        id=i;
    }
    sort(work+1,work+1+m);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            auto [c,a,b,id]=work[j];
            if(i==1){
                for(int k=0;k+a<=b;k++) f[i][j][k]=std::max(f[i][j][k],a+k);
            }
            for(int k=0;k+a<=b;k++){
                if(f[i][j][k]==0) continue;
                for(int lj=j+1;lj<=m;lj++){
                    auto [lc,la,lb,_]=work[lj];
                    if(lc<=c) continue;
                    if(a+k+D>=la and a+k+D<=lb){
                        int lk=a+k+D-(la);
                        i64 val=f[i][j][k]+a+k+D;
                        if(val>f[i+1][lj][lk]){
                            f[i+1][lj][lk]=val;
                            fa[i+1][lj][lk]={i,j,k};
                        }
                    }
                    if((a+k)*D>=la and (a+k)*D<=lb){
                        int lk=(a+k)*D-(la);
                        i64 val=f[i][j][k]+(a+k)*D;
                        if(val>f[i+1][lj][lk]){
                            f[i+1][lj][lk]=val;
                            fa[i+1][lj][lk]={i,j,k};
                        }
                    }
                }
            }
        }
    }

    i64 res=0;
    i64 day=n,idx=-1,d=-1;
    for(int j=1;j<=m;j++){
        for(int k=0;k<=100;k++){
            i64 val=f[n][j][k];
            if(val>res){
                res=val;
                idx=j,d=k;
            }
        }
    }

    if(!res){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";

    std::vector<std::array<i64,2>> ans;
    ans.pb({work[idx][3],work[idx][1]+d});
    while(day!=0){
        auto [lday,lidx,ld]=fa[day][idx][d];
        if(lday) ans.pb({work[lidx][3],work[lidx][1]+ld});
        day=lday,idx=lidx,d=ld;
    }
    reverse(all(ans));
    for(auto [x,y]:ans){
        std::cout<<x<<" "<<y<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
