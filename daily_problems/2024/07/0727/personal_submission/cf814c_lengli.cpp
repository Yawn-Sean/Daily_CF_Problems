/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=1510;

int f[26][N][N];

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    for(int c=0;c<26;c++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(s[i-1]-'a'==c){
                    f[c][i][j]=f[c][i-1][j]+1;
                }else if(j-1>=0){
                    f[c][i][j]=f[c][i-1][j-1]+1;
                }
            }
        }
    }

    std::vector<std::vector<int>> res(26,std::vector<int>(n+2,0));
    for(int c=0;c<26;c++){
        for(int i=1;i<=n;i++){
            for(int k=0;k<=i;k++){
                res[c][k]=std::max(f[c][i][k],res[c][k]);
            }
        }
        for(int j=1;j<=n;j++) res[c][j]=std::max(res[c][j-1],res[c][j]);
    }
    int q;
    std::cin>>q;
    while(q--){
        int k;
        char cr;
        std::cin>>k>>cr;
        int c=cr-'a';
        std::cout<<res[c][k]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
