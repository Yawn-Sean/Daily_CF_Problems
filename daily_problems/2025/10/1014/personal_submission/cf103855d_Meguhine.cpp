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

#define N 1000005
struct Node{
	int sum[N];
	vector<int>id[N];
	multiset<int>b;
	void add(int x,int v,int i){
		if(id[x].empty()) b.insert(0);
		id[x].emplace_back(i);
		ins(x,v);
	}
	void ins(int x,int v){
		b.extract(sum[x]);
		b.insert(sum[x]+=v);
	}
	void del(int x,int v){
		b.extract(sum[x]);
		b.insert(sum[x]-=v);
	}
	LL mx(int x){
		LL res=0;
		for(auto it=b.rbegin();x-- && it!=b.rend();++it){
			res+=*it;
		}
		return res;
	}
};
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<ai3>a(n);
	Node X,Y;
	for(int i=0;i<n;++i){
		auto& [x,y,v]=a[i];
		cin>>x>>y>>v;
		X.add(x,v,i);
		Y.add(y,v,i);
	}
	dbg(X.mx(3));
	dbg(Y.mx(3));
	LL ans=max(X.mx(3),Y.mx(3));
	for(int x=0;x<N;++x){
		if(X.id[x].empty()) continue;
		LL res=X.sum[x];
		dbg(x,res);
		for(auto& i:X.id[x]){
			Y.del(a[i][1],a[i][2]);
		}
		dbg("\t",Y.mx(2));
		res+=Y.mx(2);
		updmx(ans,res);
		for(auto& i:X.id[x]){
			Y.ins(a[i][1],a[i][2]);
		}
	}
	for(int y=0;y<N;++y){
		if(Y.id[y].empty()) continue;
		LL res=Y.sum[y];
		dbg(y,res);
		for(auto& i:Y.id[y]){
			X.del(a[i][0],a[i][2]);
		}
		dbg("\t",X.mx(2));
		res+=X.mx(2);
		updmx(ans,res);
		for(auto& i:Y.id[y]){
			X.ins(a[i][0],a[i][2]);
		}
	}
	cout<<ans;
	return 0;
}
