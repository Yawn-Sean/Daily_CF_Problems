/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            std::cin>>g[i][j];
    
    std::vector<std::vector<std::vector<int>>> cnt(n+2,std::vector<std::vector<int>> (m+2,std::vector<int> (26,0)));
    std::vector<std::vector<int>> pre_xor(n+2,std::vector<int> (m+2,0));

    string_hash shs(26);

    std::vector<std::vector<int>> hs(n+2,std::vector<int> (m+2,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<26;k++) cnt[i][j][k]+=cnt[i][j-1][k];
            int v=g[i][j]-'a';
            cnt[i][j][v]++;
            shs.build(cnt[i][j]);
            hs[i][j]=shs.get(1,26);
            pre_xor[i][j]=pre_xor[i][j-1]^(1<<v);
        }
    }

    std::vector<int> t(n*2+2);

    auto check=[&](int i,int l,int r)->bool{
        int v=pre_xor[i][r]^pre_xor[i][l-1];
        if(v) return __builtin_popcount(v)==1;
        return 1;
    };

    int res=0;

    auto cal=[&](){
        std::vector<int> p(n*2+2);
        for(int i=1,r=0,mid=0;i<=n*2;i++){
            if(t[i]<0) continue;
            if(i<r) p[i]=std::min(r-i,p[mid*2-i]);
            while(i-p[i]>=0 and i+p[i]<=n*2+1 and t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(i+p[i]>r) r=i+p[i]-1,mid=i;
            res+=p[i]/2;
        }
    };

    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            for(int k=1;k<=n;k++){
                t[k*2-1]=0;
                if(check(k,i,j)) t[k*2]=(hs[k][j]-hs[k][i-1]+shs.P)%shs.P;
                else t[k*2]=-k;
            }
            cal();
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
