/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::vector<int> init_prime(int n){
    std::vector<int> prime,st(n+1,0);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){
            st[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    return prime;
}

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    auto pr=init_prime(n+2);
    int mx=0;
    for(auto x:pr){
        if(n%x==0){
            mx=std::max(mx,x);
        }
    }
    int v=n-mx+1;

    auto get=[&](int x)->int{
        int t=(v+x-1)/x;
        if(x*t>=v and x*t<=n) {
            int ans=x*t-x+1;
            if(ans<=2) return inf;
            return ans;
        }return inf;
    };

    int res=1e9;
    for(auto x:pr){
        res=std::min(res,get(x));
    }

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
