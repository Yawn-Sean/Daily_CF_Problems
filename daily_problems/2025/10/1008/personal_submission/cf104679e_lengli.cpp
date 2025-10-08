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
	std::vector<int> prime,st(n+1,0),res(n+1,0);
	for(int i=2;i<=n;i++){
		if(!st[i]) prime.push_back(i),res[i]=1;
		for(int j=0;prime[j]*i<=n;j++){
			st[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	return res;
}

void solve(){
    auto a=init_prime(10000010);
    for(int i=1;i<=10000000;i++) a[i]+=a[i-1];
    int q;
    std::cin>>q;
    while(q--){
        int x;
        std::cin>>x;
        if(x==2) std::cout<<0<<"\n";
        else if(x==3) std::cout<<1<<"\n";
        else if(x==4) std::cout<<1<<"\n";
        else std::cout<<a[x]-a[x/2]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
