/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> a(n+2,std::vector<int> (m+2,0));
    std::vector<std::vector<int>> b(n+2,std::vector<int> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            a[i][j]=c-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1][j]==1 and a[i+1][j]==1 and a[i][j-1]==1 and a[i][j+1]==1 and a[i][j]==1){
                b[i][j]=1;
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++) b[i][j]+=b[i-1][j];
    }
    long long res=0;
    for(int l=0;l<=n;l++){
        for(int r=l+3;r<=n+1;r++){
            for(int i=1,j=3,cnt=b[r-2][2]-b[l+1][2];i<=m;i++){
                while(j<=m and cnt<k){
                    j++;
                    cnt+=b[r-2][j-1]-b[l+1][j-1];
                }
                if(cnt>=k) res+=m-j+1;
                cnt-=b[r-2][i+1]-b[l+1][i+1];
            }
        }
    }
    std::cout<<res;

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
