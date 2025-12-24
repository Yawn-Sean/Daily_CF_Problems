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

constexpr int N=1e6+5;
bitset<N>notP; int mn_p[N];
vector<int>prime;
void init_prime(const int& n=N){ // init [1,n-1]
	mn_p[1]=notP[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			notP[i*p]=1,mn_p[i*p]=p;
			if(i%p==0){
				break;
			}
		}
	}
}

void solve(){
	int n,c[2];
	cin>>n>>c[0]>>c[1];
	array<vector<int>,2>a; // a[i]: cost to ++c[i^1],--c[i]
	LL ans=0;
	for(int i=0,x;i<n;++i){
		cin>>x;
		if(x==1){
			--c[0],--c[1];
			continue;
		}
		ai2 t={0,0};
		while(x%2==0){ // del even, then ++odd
			x/=2;
			t[1]+=2;
		}
		while(x!=1){
			const int p=mn_p[x];
			t[0]+=p;
			x/=p;
		}
		if(t[0]<=t[1]){
			ans+=t[0];
			--c[0];
			a[1].emplace_back(t[1]-t[0]);
		}
		else{
			ans+=t[1];
			--c[1];
			a[0].emplace_back(t[0]-t[1]);
		}
	}
	for(int i=0;i<2;++i) if(c[i]>0){
		dbg(i,a[i].size(),c[i]);
		assert((int)a[i].size()>=c[i]);
		sort(all(a[i]));
		a[i].resize(c[i]);
		ans+=accumulate(all(a[i]),0ll);
	}
	cout<<ans<<'\n';
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init_prime();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
