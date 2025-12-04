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
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

void divide(int x,auto&& a){
	for(int p=2;x!=1 && p*p<=x;++p){
		if(x%p==0){
			int c=0;
			while(x%p==0) ++c,x/=p;
			a.push_back({p,c});
		}
		if(x==1 || p*p>x) break;
	}
	if(x!=1){
		a.push_back({x,1});
		return;
	}
}

constexpr int inf=1e9;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,K,q;
	cin>>n>>K>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<vector<int>>e(n+1);
	for(int i=2,j;i<=n;++i){
		cin>>j;
		e[j].emplace_back(i);
	}
	int timStamp=0;
	vector<int>in(n+1),out(n+1);
	auto dfs=[&](auto&& self,int u)->void{
		in[u]=++timStamp;
		for(auto v:e[u]) self(self,v);
		out[u]=timStamp;
	};
	dfs(dfs,1);
	vector<ai2>qry(q+1);
	for(int i=1;i<=q;++i){
		cin>>qry[i][0]>>qry[i][1];
	}
	vector<ai2>factors;
	divide(K,factors);
	vector<int>ans(n+1,0);
	vector<int>rest(n+1);
	auto work=[&](const int p,const int c)->void{
		dbg(p,c);
		set<int>idx;
		for(int i=1;i<=n;++i){
			const int j=in[i];
			int r=c,x=a[i];
			while(r>0 && x%p==0){
				--r,x/=p;
			}
			dbg(i,j,r);
			if(r){
				idx.insert(j);
				rest[j]=r;
			}
		}
		for(int i=1;i<=q;++i){
			auto [u,x]=qry[i];
			int sub=0;
			while(sub<c && x%p==0){
				++sub,x/=p;
			}
			dbg(i,u,in[u],out[u],sub);
			if(!sub) continue;
			for(auto it=idx.lower_bound(in[u]);it!=idx.end();){
				if(*it>out[u]) break;
				int& r=rest[*it];
				dbg("\t",*it,r,sub);
				if(r<=sub){
					updmx(ans[*it],i);
					it=idx.erase(it);
				}
				else{
					r-=sub;
					++it;
				}
			}
		}
		for(auto i:idx) ans[i]=inf;
	};
	for(auto [p,c]:factors){
		work(p,c);
	}
	for(int i=1;i<=n;++i){
		int x=ans[in[i]];
		if(x==inf) x=-1;
		cout<<x<<' ';
	}
	return 0;
}
