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
    std::vector<i64> a(n);
    i64 mi=2000000000;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        mi=std::min(mi,a[i]);
    }
    for(int i=0;i<n;i++) a[i]-=mi;
    
    int pos=x-1;
    int res=0;
    while(a[pos]){
        a[pos]--;
        pos--;
        if(pos==-1) pos=n-1;
        res++;
    }
    a[pos]+=res+1ll*mi*n;
    for(int i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
