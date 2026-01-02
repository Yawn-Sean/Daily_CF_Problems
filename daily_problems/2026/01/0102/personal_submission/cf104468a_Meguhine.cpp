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

struct DSU{
	vector<int>fa,siz;
	DSU(){}
	DSU(int n){
		init(n);
	}
	void init(int n){
		fa.resize(n);
		iota(fa.begin(),fa.end(),0);
		siz.assign(n,1);
	}
	int get(int x){
		while(x!=fa[x]){
			x=fa[x]=fa[fa[x]];
		}
		return x;
	}
	bool same(int x,int y){
		return get(x)==get(y);
	}
	bool merge(int x,int y){
		x=get(x),y=get(y);
		if(x==y) return 0;
		if(siz[y]>siz[x]) swap(x,y);
		siz[x]+=siz[y],fa[y]=x;
		return 1;
	}
	int size(int x){
		return siz[get(x)];
	}
};

#define FAIL {cout<<"-1\n";return;}
void solve(){
	int n; cin>>n;
	DSU dsu(n*2); // i: not change, i+n: change
	const int m=n*2;
	vector<ai2>a(n);
	vector<vector<ai2>>pos(m);
	for(int i=0;i<n;++i){
		auto& [x,y]=a[i];
		cin>>x>>y;
		--x,--y;
		pos[x].push_back({i,0});
		pos[y].push_back({i,1});
	}
	for(int x=0;x<m;++x){
		if(pos[x].size()>2) FAIL;
		if(pos[x].size()!=2) continue;
		const auto& [i,pi]=pos[x][0];
		const auto& [j,pj]=pos[x][1];
		if(pi==pj){
			dsu.merge(i,j+n);
			dsu.merge(i+n,j);
		}
		else{
			dsu.merge(i,j);
			dsu.merge(i+n,j+n);
		}
	}
	vector<int>tot(n),cnt(n);
	for(int x=0;x<n*2;++x){
		if(x<n && dsu.same(x,x+n)) FAIL;
		const int t=dsu.get(x);
		if(t<n){
			++tot[t];
			if(x<n) ++cnt[t];
		}
	}
	int ans=0;
	for(int x=0;x<n;++x){
		if(dsu.get(x)==x){
			ans+=min(cnt[x],tot[x]-cnt[x]);
		}
	}
	cout<<ans<<"\n";
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
