#include<bits/stdc++.h>
using namespace std;
const int N=550;
typedef long long LL;
int dx[]={0,0,-1,1},
    dy[]={-1,1,0,0};
LL a[N][N],s[N][N];

void solve(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char x;cin>>x;
            a[i][j]=(x=='1'?1:0);
        }
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            int ok=1;
            for(int k=0;k<4;k++){
                int u=i+dx[k],v=j+dy[k];
                if(!a[u][v]){
                    ok=0;break;
                }
            }
            if(!a[i][j])ok=0;
            s[i][j]=ok+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }

    auto sum=[&](int x,int y,int u,int v)->int{
        return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
    };

    LL ans=0;
    for(int x=2;x<n;x++){
        for(int y=2;y<n;y++){
            for(int u=2,v=2;u<m;u++){
                while(v<m&&sum(x,u,y,v)<k)v++;
                if(v>=m)break;
                ans+=m-v;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
