/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

int cnt_p[100010],cnt_c[100010];
int f[510][5010],v[20];

void solve(){
    int n,k;
    std::cin>>n>>k;
    for(int i=1;i<=n*k;i++) {
        int x;
        std::cin>>x;
        cnt_c[x]++;    
    }
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        cnt_p[x]++;
    }
    for(int i=1;i<=k;i++) std::cin>>v[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n*k;j++){
            for(int now=0;now<=std::min(j,k);now++){
                f[i][j]=std::max(f[i-1][j-now]+v[now],f[i][j]);
            }
        }
    }

    long long res=0;
    for(int i=1;i<=100000;i++){
        res+=f[cnt_p[i]][cnt_c[i]];
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
