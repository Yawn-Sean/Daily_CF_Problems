#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

/*
goal is to use minimum op1, which is add 1 to an element
cost = max * n - accumutale({a})
so the goal is to use op2 to minimum "max{a}"
- if k+2<=n, op2 <=> ++a[i], --a[j]
	how? cause k => (k-1)
		e.g. k=3:
		+3 -1 -1 -1  0
		 0 -1 -1 +3 -1
		 0 -1 +3 -1 -1
		 0 +3 -1 -1 -1
		--------------
		+3  0  0  0 -3
		-1 -1 -1  0 +3
		--------------
		+2 -1 -1  0  0
	so just trivial math calculation
- if k+1==n
	-1, +k, mod n
*/

void solve(){
	int n,m; cin>>n>>m;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	if(m+1==n){
		vector<int>cnt(n);
		for(auto x:a){
			++cnt[x%n];
		}
		LL res=0;
		for(int r=1;r<n;++r){
			res+=1ll*cnt[r]*(n-r);
		}
		LL ans=res;
		for(int r=1;r<n;++r){
			res+=n;
			res-=1ll*cnt[r]*n;
			updmn(ans,res);
		}
		cout<<ans<<'\n';
	}
	else{
		LL sum=accumulate(all(a),0ll);
		LL avg=sum/n;
		int ans=n-int(sum-avg*n);
		if(ans==n) ans=0;
		cout<<ans<<'\n';
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
