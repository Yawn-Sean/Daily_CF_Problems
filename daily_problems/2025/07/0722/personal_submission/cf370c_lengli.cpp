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
    std::vector<int> a(n);
    for(int i=0;i<n;i++) std::cin>>a[i];
    std::sort(all(a));

    int cnt=0;
    for(int i=0;i<n;i++) cnt+=(a[i]!=a[(i+(n/2))%n]);
    std::cout<<cnt<<"\n";
    for(int i=0;i<n;i++) std::cout<<a[i]<<" "<<a[(i+(n/2))%n]<<"\n"; 
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
