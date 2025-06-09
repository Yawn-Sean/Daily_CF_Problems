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

void solve(){
    int n,m;
    std::cin>>n>>m;
    auto get=[&](int l,int r){
        return l*n+r;
    };

    std::vector<std::vector<int>> f(n+2,std::vector<int> (m+2,0));


    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        for(int j=m;j>=1;j--){
            if(s[j-1]=='1') {
                f[i][j]=1,f[i][j]+=f[i][j+1];
            }else f[i][j]=0;
        }
    }

    int res=0;

    std::vector<int> cnt(m+2);

    for(int i=1;i<=m;i++){
        for(int t=1;t<=n;t++) cnt[f[t][i]]++;

        int k=0;
        for(int j=m;j>=1;j--){
            if(cnt[j]){
                k+=cnt[j];
                res=std::max(res,k*j);
            }
        }

        for(int t=1;t<=n;t++) cnt[f[t][i]]--;
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
