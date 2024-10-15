/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=10000010;

#define int long long

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> f(N,0);
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        f[x]++;
    }
    int sum=0;
    for(int i=N-10;i>=1;i--){
        sum+=f[i];
        if(i*2<N) sum-=f[i*2];
        if(i*2-1<N and i!=1) sum-=f[i*2-1];
        if(sum>=k){
            std::cout<<i<<"\n";
            return;
        }
        f[i/2]+=f[i];
        f[(i+1)/2]+=f[i];
    }
    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
