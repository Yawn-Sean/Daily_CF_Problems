/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    std::string q="RGB";

    std::vector<std::vector<int>> a(n+2,std::vector<int> (3,0));

    int res=1e9;
    for(int j=1;j<=3;j++){
        for(int i=1;i<=n;i++){
            if(s[i-1]!=q[(i+j)%3]) a[i][j]=a[i-1][j]+1;
            else a[i][j]=a[i-1][j];
            if(i>=k){
                int mx=a[i][j]-a[i-k][j];
                res=std::min(res,mx);
            }
        }
        
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
