#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
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
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

void solve(){
	int n; cin>>n;
	const int m=n/2;
	vector<int>a,b;
	for(int i=0,x;i<m;++i){
		cin>>x;
		if(x<=m) a.emplace_back(x);
		else b.emplace_back(x);
	}
	for(int i=0,x;i<m;++i){
		cin>>x;
		if(x<=m) b.emplace_back(x);
		else a.emplace_back(x);
	}
	cout<<((!!a.size())+(!!b.size()))<<'\n';
	if(a.size()){
		cout<<a.size();
		for(auto& x:a) cout<<' '<<x;
		cout<<'\n';
	}
	if(b.size()){
		cout<<b.size();
		for(auto& x:b) cout<<' '<<x;
		cout<<'\n';
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
