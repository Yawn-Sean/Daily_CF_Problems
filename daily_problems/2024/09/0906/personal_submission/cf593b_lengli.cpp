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
    int l,r;
    std::cin>>l>>r;
    std::vector<long long> k(n),b(n);
    for(int i=0;i<n;i++) std::cin>>k[i]>>b[i];
    std::vector<std::array<int,2>> a(n);
    for(int i=0;i<n;i++){
        a[i][0]=l*k[i]+b[i];
        a[i][1]=r*k[i]+b[i];
    }
    sort(all(a));
    bool flag=0;
    for(int i=1;i<n;i++){
        if(a[i][1]<a[i-1][1]) flag=1;
    }
    std::cout<<(flag ? "YES" : "NO")<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
