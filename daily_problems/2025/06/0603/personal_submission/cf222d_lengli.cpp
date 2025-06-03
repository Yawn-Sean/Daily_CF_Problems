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
    int n,x;
    std::cin>>n>>x;
    std::vector<int> a(n),b(n);
    for(auto &x:a) std::cin>>x;
    for(auto &x:b) std::cin>>x;
    sort(all(a));
    sort(all(b));
    int cnt=0;
    for(int i=0,j=n-1;i<n;i++){
        if(a[i]+b[j]>=x) j--,cnt++;
    }
    std::cout<<1<<" "<<cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
