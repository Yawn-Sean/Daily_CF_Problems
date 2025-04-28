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
    i64 n,k;
    std::cin>>n>>k;

    std::vector<i64> f(n+2);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+i-1;
    }

    if(f[n] < k){
        std::cout<<"Impossible"<<"\n";
        return;
    }

    std::string res="";

    auto dfs=[&](auto self,i64 n,i64 k)->void{
        if(n<=0) return;
        if(f[n-1]>=k){
            res+="()";
            self(self,n-1,k);
        }else{
            res+="(";
            self(self,n-1,k-n+1);
            res+=")";
        }
    };


    dfs(dfs,n,k);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
