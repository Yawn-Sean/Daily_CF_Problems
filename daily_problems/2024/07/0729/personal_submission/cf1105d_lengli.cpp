/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,k;
    std::cin>>n>>k;
    k--;
    std::vector<int> res(n+2);
    int l=1,r=n;
    for(int i=1;i<n;i++){
        if(k>>(n-i-1)&1) res[r]=i,r--;
        else res[l]=i,l++;
    }
    res[l]=n;
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
