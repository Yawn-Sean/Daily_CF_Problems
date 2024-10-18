/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back


Mint f[110][3000];

void init(){
    f[0][0]=1;
    for(int i=1;i<=100;i++){
        for(int j=i;j<=26*i;j++){
            for(int k=1;k<=26 and j-k>=0;k++){
                f[i][j]+=f[i-1][j-k];
            }
        }
    }
}

void solve(){
    std::string s;
    std::cin>>s;
    int len=s.size(),sum=0;
    for(auto x:s) sum+=x-'a'+1;
    std::cout<<f[len][sum]-1<<"\n";
}

signed main(){
    fastio;
    init();
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
