#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
char c[]={'R','G','B'};
int f[N][3];

void solve(){
    int n,k;cin>>n>>k;
    string s;
    cin>>s;s=' '+s;
    for(int j=0;j<3;j++)
        f[0][j]=0;
    

   
    //cout<<r[0]<<"\n";
    //cout<<r[1]<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            f[i][j]=(c[(i+j)%3]!=s[i]);
            f[i][j]+=f[i-1][j];
           // cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
        }
    }

    int ans=N;
    for(int i=k;i<=n;i++){
        for(int j=0;j<3;j++){
            ans=min(ans,f[i][j]-f[i-k][j]);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
