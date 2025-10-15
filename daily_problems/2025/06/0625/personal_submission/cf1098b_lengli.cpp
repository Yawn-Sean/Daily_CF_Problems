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
    std::vector<std::vector<char>> g(n,std::vector<char> (m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) std::cin>>g[i][j];
    std::string s="AGTC";

    int res=inf;
    std::vector<std::vector<char>> out;

    auto check_col=[&](std::string a,std::string b)->void{
        int ans=0;
        std::vector<std::vector<char>> tmp(n,std::vector<char> (m));
        for(int i=0;i<n;i++){
            int cnt1=0,cnt2=0;
            for(int j=0;j<m;j++){
                if(a[j%2]!=g[i][j]) cnt1++;
            }
            std::swap(a[0],a[1]);
            for(int j=0;j<m;j++){
                if(a[j%2]!=g[i][j]) cnt2++;
            }

            if(cnt1<cnt2) std::swap(a[0],a[1]);
            for(int j=0;j<m;j++){
                tmp[i][j]=a[j%2];
            }

            ans+=std::min(cnt1,cnt2);
            std::swap(a,b);
        }
        if(ans<res) res=ans,out.swap(tmp);
    };

    auto check_row=[&](std::string a,std::string b)->void{
        int ans=0;
        std::vector<std::vector<char>> tmp(n,std::vector<char> (m));
        for(int j=0;j<m;j++){
            int cnt1=0,cnt2=0;
            for(int i=0;i<n;i++){
                if(a[i%2]!=g[i][j]) cnt1++;
            }
            std::swap(a[0],a[1]);
            for(int i=0;i<n;i++){
                if(a[i%2]!=g[i][j]) cnt2++;
            }
            if(cnt1<cnt2) std::swap(a[0],a[1]);
            for(int i=0;i<n;i++){
                tmp[i][j]=a[i%2];
            }
            ans+=std::min(cnt1,cnt2);
            std::swap(a,b);
        }
        if(ans<res) res=ans,out.swap(tmp);
    };

    for(int mask=0;mask<(1<<4);mask++){
        if(__builtin_popcount(mask)!=2) continue;
        std::string l="",r="";
        for(int i=0;i<4;i++){
            if(mask>>i&1) l+=s[i];
            else r+=s[i];
        }
        check_col(l,r);
        check_row(l,r);
    }
    
    for(auto x:out){
        for(auto y:x) std::cout<<y;
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
