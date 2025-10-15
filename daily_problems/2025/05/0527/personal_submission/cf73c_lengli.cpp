/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

int f[110][110][26];
int v[26][26];

void solve(){
    std::string s;
    int k;
    std::cin>>s>>k;
    int m;
    std::cin>>m;

    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            for(int k=0;k<26;k++) f[i][j][k]=-inf;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++) v[i][j]=-inf;
    }

    for(int i=1;i<=m;i++){
        char l,r;
        int x;
        std::cin>>l>>r>>x;
        int a=l-'a',b=r-'a';
        v[a][b]=std::max(v[a][b],x);
    }

    int n=s.size();

    for(int i=0;i<26;i++){
        int v=s[0]-'a';
        f[1][v==i ? 0 : 1][i]=0;
    }

    int res=-inf;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int x=0;x<26;x++){
                for(int la=0;la<26;la++){
                    int get=(v[la][x]==-inf ? 0 : v[la][x]);
                    if(j-(x==s[i-1]-'a' ? 0 : 1)>=0) f[i][j][x]=std::max(f[i][j][x],f[i-1][j-(x==s[i-1]-'a' ? 0 : 1)][la]+get);
                }
            }
        }
    }

    for(int j=0;j<=k;j++){
        for(int x=0;x<26;x++){
            res=std::max(res,f[n][j][x]);
        }
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
