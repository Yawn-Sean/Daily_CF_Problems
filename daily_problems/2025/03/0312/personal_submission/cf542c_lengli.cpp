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
    
    i64 res=1,idx=0;
    for(int i=1;i<=n;i++){
        int x=a[i],len=0;
        std::vector<int> st(n+2,0);
        while(!st[x]){
            st[x]=++len;
            x=a[x];
        }
        idx=std::max(idx,1ll*st[x]-1);
        res=std::lcm(res,len-st[x]+1);
    }
    for(int i=1;i;i++){
        if(res*i>idx){
            std::cout<<res*i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
