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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    i64 suf=0;
    std::vector<int> res(n+2,0),f(n+2,0);
    for(int i=n;i>=1;i--){
        if(suf>a[i]) res[i]=1,suf-=a[i];
        else{
            f[i+1]=1;
            res[i]=0;
            suf=(i64)a[i]-suf;
        }
    }
    for(int i=1,j=0;i<=n;i++){
        j^=f[i];
        if(res[i]==1) std::cout<<(j ? "+" : "-");
        else std::cout<<(j ? "-" : "+");
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
