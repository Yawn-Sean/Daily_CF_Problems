/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::vector<int> sieve(int n){
    std::vector<int> prime,st(n+2);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.pb(i);
        for(int j=0;prime[j]*i<=n;j++){
            st[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    return prime;
}

std::vector<int> pr;

void solve(){
    int n;
	std::cin>>n;
	std::vector<int> a(n);
	for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    a.erase(std::unique(all(a)),a.end());
    int m=pr.size();

    i64 res=4e18;

    for(int i=0;i<(1<<m);i++){
        i64 v=1;
        for(int j=0;j<m;j++){
            if(i>>j&1) v=v*pr[j];
        }
        int cnt=1;
        for(i64 x:a) if(std::gcd(x,v)<=1) cnt=0;
        if(cnt){
            res=std::min(res,v);
        }
    }

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    pr=sieve(50);
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
