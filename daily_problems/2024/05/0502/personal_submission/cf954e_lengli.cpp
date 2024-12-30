// Problem: E. Water Taps
// Contest: Codeforces - Educational Codeforces Round 40 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/954/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n,t;
	cin>>n>>t;
	vector<array<int,2>> a(n);
	
	for(int i=0;i<n;i++) cin>>a[i][0];
	for(int i=0;i<n;i++) cin>>a[i][1],a[i][1]-=t;
	
	sort(all(a),[&](auto l,auto r){
		return l[1]<r[1];
	});
	
	vector<array<int,2>> q,p;
	int z=0,f=0;
	double res=0;
	for(auto [l,r]:a){
		if(r<0) f-=r*l,q.pb({l,-r});
		else if(r>0) z+=r*l,p.pb({l,r});
		else res+=l;
	}
	if(z==f){
		for(auto [l,r]:q) res+=l;
		for(auto [l,r]:p) res+=l;
		cout<<fixed<<setprecision(10)<<res<<endl;
	}else if(z>f){
		int sum=0;
		for(auto x:q) res+=x[0],sum+=x[0]*x[1];
		for(auto [l,r]:p){
			if(sum==0) break;
			if(sum-l*r>=0) res+=l,sum-=l*r;
			else{
				double d=(double)sum/(double)r;
				res+=d;
				sum=0;
			}
		}
		cout<<fixed<<setprecision(10)<<res<<endl;
	}else{
		reverse(all(q));
		int sum=0;
		for(auto x:p) res+=x[0],sum+=x[0]*x[1];
		for(auto [l,r]:q){
			if(sum==0) break;
			if(sum-l*r>=0) res+=l,sum-=l*r;
			else{
				double d=(double)sum/(double)r;
				res+=d;
				sum=0;
			}
		}
		cout<<fixed<<setprecision(10)<<res<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
