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
    std::vector<std::string> s(n);
    for(auto &x:s) std::cin>>x;
    std::vector<std::vector<int>> a(n+2,std::vector<int>(m+2));
    int res=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            a[i][j]=a[i+1][j]+a[i][j+1]-a[i+1][j+1];
            if(s[i][j]=='W'){
                if(a[i][j]!=1) a[i][j]=1,res++;
            }else{
                if(a[i][j]!=-1) a[i][j]=-1,res++;
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
