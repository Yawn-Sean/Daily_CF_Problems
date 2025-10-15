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
    int m;
    std::cin>>m;
    for(int i=1;i<=m;i++){
        int x;
        std::cin>>x;
        a[x]*=-1;
    }
    std::vector<int> stk;
    for(int i=n;i>=1;i--){
        if(a[i]>=0){
            if(stk.size() and stk.back()==-a[i]) stk.pop_back();
            else {
                stk.pb(-a[i]);
                a[i]*=-1;
            }
        }else stk.pb(a[i]);
    }
    if(stk.size()) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";

    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
