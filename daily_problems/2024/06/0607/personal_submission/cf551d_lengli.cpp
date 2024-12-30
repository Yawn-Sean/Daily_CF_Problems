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
    long long n,k,l;
    std::cin>>n>>k>>l>>M;
    matrix<int> f(2,1);
    f[0][0]=2,f[1][0]=1;
    matrix<int> t(2,2);
    t[0][0]=t[0][1]=1;
    t[1][0]=1;
    t^=(n-2);
    t=t*f;
    if(l<62 and (1ll<<l)<=k){
        std::cout<<"0"<<"\n";
        return;
    }
    long long res=1;
    long long a=(t[0][0]+t[1][0])%M;
    long long b=((qmi(2,n)+M)%M-a+M)%M;
    bool flag=0;
    for(int i=l-1;i>=0;i--){
        if(k>>i&1) res=(res*b)%M;
        else res=(res*a)%M;
    }
    std::cout<<res%M;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
