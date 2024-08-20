/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int l=1,r=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) l++;
        else break;
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]>a[i+1]) r++;
        else break;
    }
    if(l&1 or r&1) std::cout<<"Alice"<<"\n";
    else std::cout<<"Bob"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
