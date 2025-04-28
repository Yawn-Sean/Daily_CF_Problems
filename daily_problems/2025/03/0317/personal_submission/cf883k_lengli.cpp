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
    std::vector<std::array<int,2>> a(n);
    for(auto &[g,y]:a) std::cin>>g>>y;

    std::vector<int> f(n);
    f[0]=a[0][0]+a[0][1];

    for(int i=1;i<n;i++) f[i]=std::min(a[i][0]+a[i][1],f[i-1]+1);

    for(int i=n-2;i>=0;i--) f[i]=std::min(f[i],f[i+1]+1);
    
    std::vector<int> res;
    i64 sum=0;
    for(int i=0;i<n;i++){
        if(f[i]<a[i][0]){
            std::cout<<"-1"<<"\n";
            return;
        }
        sum+=f[i]-a[i][0];
    }
    std::cout<<sum<<"\n";
    for(auto x:f) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
