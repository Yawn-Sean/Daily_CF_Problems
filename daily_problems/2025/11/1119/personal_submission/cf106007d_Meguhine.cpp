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
	int n;
	cin>>n;
	vector<string>e(n);
	for(auto& s:e) cin>>s;
	vector<bool>vis(n);
	vis[0]=1;
	queue<int>p;
	p.push(0);
	vector<ai2>ans;
	while(p.size()){
		int u=p.front();
		p.pop();
		for(int v=0;v<n;++v){
			if(e[u][v]=='0' || vis[v]) continue;
			vis[v]=1;
			p.push(v);
			ans.push_back({u,v});
		}
	}
	if(ans.size()!=(n-1)){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	reverse(all(ans));
	for(auto& [x,y]:ans){
		cout<<(++x)<<' '<<(++y)<<'\n';
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
