/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+1),st(n+1);
    for(int i=0;i<=n;i++) a[i]=i;

    for(int i=n;i>=0;i--){
        if(st[i]) continue;
        int k=0;
        for(int j=0;j<25;j++){
            if(i>>j&1) k=j;
        }
        int v=(1<<(k+1))-1;
        int l=i,r=v^i;
        if(st[l] or st[r]) continue;
        std::swap(a[l],a[r]);
        st[l]=1,st[r]=1;
    }
    i64 res=0;
    for(int i=0;i<=n;i++) res+=(i^a[i]);
    std::cout<<res<<"\n";
    for(auto x:a) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
