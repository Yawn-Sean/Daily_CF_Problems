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
    std::vector<std::string> q={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

    std::vector<std::string> s(n+2);
    std::vector<std::vector<int>> g(n+2,std::vector<int> (10,-1));

    for(int t=1;t<=n;t++){
        std::cin>>s[t];
        for(int i=9;i>=0;i--){
            int cnt=0;
            for(int j=0;j<7 and cnt!=-1;j++){
                if(s[t][j]=='1' and q[i][j]=='0') cnt=-1;
                if(s[t][j]=='0' and q[i][j]=='1') cnt++;
            }
            g[t][i]=cnt;
        }
    }
    std::vector<std::vector<int>> f(n+2,std::vector<int> (m+2,0));
    f[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int k=9;k>=0;k--){
            if(g[i][k]!=-1){
                for(int j=m;j>=g[i][k];j--){
                    f[i][j]|=f[i+1][j-g[i][k]];
                }
            }
        }
    }
    if(!f[1][m]){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::string res="";

    for(int i=1;i<=n;i++){
        for(int j=9;j>=0;j--){
            if(g[i][j]!=-1 and m>=g[i][j] and f[i+1][m-g[i][j]]){
                res+=(j+'0');
                m-=g[i][j];
                break;
            }
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
