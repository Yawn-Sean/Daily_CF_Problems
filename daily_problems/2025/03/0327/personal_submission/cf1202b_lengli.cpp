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
    std::string s;
    std::cin>>s;

    auto get=[&](int x,int y){
        std::vector<std::vector<int>> d(10,std::vector<int> (10,inf));
        for(int i=0;i<10;i++) d[i][(i+x)%10]=d[i][(i+y)%10]=1;
        for(int k=0;k<10;k++){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int res=0;
        for(int i=0;i<(int)s.size()-1;i++){
            int l=s[i]-'0',r=s[i+1]-'0';
            if(d[l][r]>=inf) return -1;
            res+=d[l][r]-1;
        }
        return res;
    };

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) std::cout<<get(i,j)<<" ";
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
