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
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<int> f(5010,0),g(5010,0);
    for(auto &x:a) std::cin>>x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j]) f[a[i]-a[j]]++;
        }
    }
    for(int i=0;i<5010;i++){
        for(int j=0;j<5010 and i+j<5010;j++){
            g[i+j]+=f[i]*f[j];
        }
    }
    int k=n*(n-1)/2,cnt=0;
    k=k*k*k;
    for(int i=5009;i>=0;i--) f[i]+=f[i+1];
    for(int i=0;i<5010;i++){
        cnt+=g[i]*f[i+1];
    }
    double res=(double)cnt/k;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
