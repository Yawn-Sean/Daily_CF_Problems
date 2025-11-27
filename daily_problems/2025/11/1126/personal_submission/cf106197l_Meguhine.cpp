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

void bf(){
	int n; cin>>n;
	vector<string>s(n);
	vector<int>sr(n),sc(n);
	auto check=[&]()->void{
		auto b=sr;
		b.insert(b.end(),all(sc));
		sort(all(b));
		for(int i=1;i<b.size();++i){
			assert(b[i-1]!=b[i]);
		}
	};
	for(auto& t:s) cin>>t;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			sr[i]+=s[i][j]-'0';
			sc[j]+=s[i][j]-'0';
		}
	}
	check();
	dbg("ok");
}

void solve(){
	int n; cin>>n;
	vector a(n,string(n,'1'));
	for(int i=0;i<n;++i){
		for(int j=1;j<=i;++j){
			a[i][n-j]+=2;
		}
	}
	for(int i=0;i<n;++i) ++a[n-1][i];
	for(auto& s:a) cout<<s<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
//	while(1) bf();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
