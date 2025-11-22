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

template<typename T> // T is int or LL
struct Fenwick{
	int n,LOG;
	vector<T>c;
	inline int lowbit(const int& x){
		return x&(-x);
	}
	Fenwick(int n_){
		init(n_);
	}
	void init(int n_){
		c.assign(n=n_,T(0));
		LOG=__lg(n)+1;
	}
	void add(int i,T x){
		for(;i<n;i+=lowbit(i)) c[i]+=x;
	}
	T query(int i){
		T res=0;
		for(;i;i-=lowbit(i)) res+=c[i];
		return res;
	}
	int kth(T k){ // min p that sum(1,p)>=k
		int ans=0; T cnt=0;
		for(int i=LOG;~i;--i) {
			int nxt=ans+(1<<i);
			if(nxt<n && cnt+c[nxt]<k){
				cnt+=c[nxt];
				ans=nxt;
			}
		}
		return ans+1;
	}
};

#include<ext/pb_ds/assoc_container.hpp>
using __gnu_pbds::gp_hash_table;

void solve(){
	int n; cin>>n;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	gp_hash_table<int,int>mp;
	vector<vector<int>>add(n+1);
	for(int i=n;i>0;--i){
		mp[b[i]]=i;
		auto it=mp.find(a[i]);
		if(it!=mp.end()){
			add[it->second].emplace_back(i);
		}
	}
	mp.clear();
	Fenwick<int>fen(n+1);
	LL ans=0;
	for(int i=1;i<=n;++i){
		for(auto x:add[i]){
			fen.add(x,1);
			dbg(i,x);
		}
		mp[b[i]]=i;
		auto it=mp.find(a[i]);
		int j=(it==mp.end())?0:(it->second);
		dbg(i,fen.query(i),j,fen.query(j));
		ans+=fen.query(i)-fen.query(j);
	}
	cout<<ans<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
