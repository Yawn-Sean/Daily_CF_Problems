/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> s(n+2);
    for(int i=1;i<=n;i++){
        std::string str;
        std::cin>>str;
        for(int j=1;j<=m;j++){
            int c=str[j-1]-'0';
            if(c==1) s[i].pb(j);
        }
    }
    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2,inf));

    for(int i=1;i<=n;i++){
        auto &q=s[i];
        for(int len=0;len<=q.size();len++){
            int ans=inf;
            for(int r=0,l=0;r<q.size();r++){
                while(r-l+1>len) l++;
                if(r-l+1==len){
                    int v=(r>=l ? q[r]-q[l]+1 : 0);
                    ans=std::min(v,ans);
                }
            }
            g[i][q.size()-len]=ans;
        }
        if(q.empty()) g[i][0]=0;
    }

    std::vector<std::vector<int>> f(n+2,std::vector<int> (k+2,inf));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int la=0;la<=j;la++){
                int d=j-la;
                if(d>m or g[i][d]==inf) continue;
                f[i][j]=std::min(f[i][j],f[i-1][la]+g[i][d]);
            }
        }
    }
    int res=inf;
    for(int i=0;i<=k;i++){
        res=std::min(res,f[n][i]);
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
