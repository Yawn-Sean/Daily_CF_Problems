// Problem: B2. K for the Price of One (Hard Version)
// Contest: Codeforces - Codeforces Round 610 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1282/B2
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

const int N=100010;

void solve(){
	int n,p,k;
	std::cin>>n>>p>>k;
	std::vector<int> a(n+2);
	for(int i=1;i<=n;i++) std::cin>>a[i];
	std::vector<int> sum(k+2,0);
	std::vector<int> b(n+2);
	sort(a.begin()+1,a.end()-1);
	for(int i=1;i<=n;i++) {
		b[i]=a[i]+b[i-1],sum[i%k]+=a[i];
	}
	
	for(int i=n;i>=1;i--){
		int t=i%k;
		int res=sum[t]+b[t]+(t ? -a[t] : 0ll);
		if(res<=p){
			std::cout<<i<<"\n";
			return;
		}
		sum[t]-=a[i];
	}
	
	
	std::cout<<0<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
