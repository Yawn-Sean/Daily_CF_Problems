/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=5010;

int n,a[N];
int l[N],r[N],st[N];
int g[N][N];
int f[N];

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(!l[a[i]]) l[a[i]]=i;
        else r[a[i]]=i;
    }
    memset(g,-1,sizeof g);
    for(int i=1;i<=n;i++){
        int cnt=0,x=0;
        memset(st,0,sizeof st);
        for(int j=i;j<=n;j++){
            if(r[a[j]]<=j and l[a[j]]>=i){
                if(st[a[j]]) st[a[j]]=0,cnt--;
                x^=a[j];
            }else if(!st[a[j]]) st[a[j]]=1,cnt++;
            if(!cnt) g[i][j]=x;
        }
    } 

    for(int i=1;i<=n;i++){
        f[i]=std::max(f[i-1],f[i]);
        for(int j=1;j<=i;j++){
            if(g[j][i]!=-1){
                f[i]=std::max(f[j-1]+g[j][i],f[i]);
            }
        }
    }
    std::cout<<f[n]<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
