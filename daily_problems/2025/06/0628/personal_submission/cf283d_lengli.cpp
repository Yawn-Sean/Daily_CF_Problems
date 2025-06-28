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
    int n,k;
    std::cin>>n;
    std::vector<i64> a(n+2);
    std::vector<int> f(n+2),p(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        while(a[i]%2==0){
            p[i]++;
            a[i]/=2;
        }
    }

    auto check=[&](int l,int r,int len)->bool{
        if(!l) return len>=r+1;
        if(l<r){
            if(r-l+1==len) return 1;
        }
        return len>=r+2;
    };

    int res=0;
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]%a[i]==0 and check(p[j],p[i],i-j+1)){
                f[i]=std::max(f[i],f[j]+1);
            }
        }
        res=std::max(res,f[i]);
    }
    std::cout<<n-res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
