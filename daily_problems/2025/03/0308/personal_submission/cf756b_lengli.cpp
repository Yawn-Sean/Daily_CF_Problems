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
    std::vector<int> f(n+2),a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    sort(a.begin()+1,a.end()-1);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+20;
        int x=std::lower_bound(a.begin()+1,a.begin()+i+1,a[i]-89)-a.begin()-1;
        f[i]=std::min(f[i],f[x]+50);
        int y=std::lower_bound(a.begin()+1,a.begin()+i+1,a[i]-1439)-a.begin()-1;
        f[i]=std::min(f[i],f[y]+120);
    }
    for(int i=1;i<=n;i++) std::cout<<f[i]-f[i-1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
