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
    int res=0;
    for(int i=0;i<n;i++){
        int k,a;
        std::cin>>k>>a;
        int ans=0;
        if(a==1){
            ans=k+1;
        }else{
            ans=k+(31-__builtin_clz(a - 1))/2+1;
        }
        res=std::max(res,ans);
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
