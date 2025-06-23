/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=110;

int f[N][N][N*2][2];

void solve(){
    std::string s;
    std::cin>>s;
    int k;
    std::cin>>k;
    f[0][0][100][0]=1;

    int n=s.size();
    
    for(int i=0;i<n;i++){
        char c=s[i];
        for(int j=0;j<=k;j++){
            for(int pos=0;pos<=200;pos++){
                for(int fx=0;fx<2;fx++){
                    if(f[i][j][pos][fx]==0) continue;
                    if(c=='F'){
                        for(int d=0;j+d<=k;d+=2) f[i+1][j+d][pos+(fx ? 1 : -1)][fx]=1;
                        f[i+1][j+1][pos][fx^1]=1;
                    }else{
                        for(int d=0;j+d<=k;d+=2) f[i+1][j+d][pos][fx^1]=1;
                        f[i+1][j+1][pos+(fx ? 1 : -1)][fx]=1;
                    }
                }
            }
        }
    }

    int res=0;
    for(int pos=0;pos<=200;pos++){
        for(int fx=0;fx<2;fx++){
            if(f[n][k][pos][fx]){
                int dis=std::abs(pos-100);
                res=std::max(res,dis);
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
