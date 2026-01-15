/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1000010;

int st[N];

auto init_prime=[](){
	std::vector<int> prime;
	for(int i=2;i<N;i++){
		if(!st[i]) prime.push_back(i),st[i]=i;
		for(int j=0;prime[j]*i<N;j++){
			st[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	return 0;
}();

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> l(n),r(n);
    for(auto &x:l) std::cin>>x;
    for(auto &x:r) std::cin>>x;
    int x=-1;

    for(int i=0;i<n;i++){
        if(l[i]==r[i]) x=l[i];
    }

    if(x==-1){
        std::cout<<"YES"<<"\n";
        for(int i=0;i<n;i++){
            if(l[i]&1) std::cout<<l[i]+1<<" ";
            else std::cout<<l[i]<<" ";
        }
        std::cout<<"\n";
        return;
    }

    std::vector<int> p;
    while(st[x]){
        p.pb(st[x]);
        int v=st[x];
        while(x%v==0) x/=v;
    }

    for(auto k:p){
        std::vector<int> res;
        for(int i=0;i<n;i++){
            int v=(r[i]/k)*k;
            if(v>=l[i]) res.pb(v);
            else{
                res.clear();
                break;
            }
        }
        if(res.size()){
            std::cout<<"YES"<<"\n";
            for(int i=0;i<n;i++){
                std::cout<<res[i]<<" ";
            }
            std::cout<<"\n";
            return;
        }
    }

    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
