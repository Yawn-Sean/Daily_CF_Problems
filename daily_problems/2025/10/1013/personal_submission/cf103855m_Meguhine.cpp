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

/*
consider (pi,qi) as a point
 min(|pi-pj|,|qi-qj|)
=|pi-pj|+|qi-qj|-max(|pi-pj|,|qi-qj|)
=|pi-pj|+|qi-qj|-Chebyshev(i,j)
xi=(pi+qi)
yi=(pi-qi)
Chebyshev(i,j)=(|xi-xj|+|yi-yj|)/2
now, use fenwick
*/

template<typename T>//T is int or LL
class Fenwick{
private:
	int n;
	vector<T>c;
	inline int lowbit(const int& x){
		return x&(-x);
	}
public:
	Fenwick(){}
	Fenwick(int n_){
		init(n_);
	}
	void init(int n_){
		c.assign(n=n_,T{});
	}
	void add(int i,T x){
		for(;i<n;i+=lowbit(i)) c[i]+=x;
	}
	T query(int i){
		T res{};
		for(;i;i-=lowbit(i)) res+=c[i];
		return res;
	}
};

struct Node{
	LL s; int c;
	Node& operator +=(const Node& x){
		s+=x.s,c+=x.c;
		return *this;
	}
};
Fenwick<Node>fen;
LL work(auto&& a){
	dbg(a);
	LL res=0;
	int mn=114514,mx=0;
	for(auto& x:a){
		updmn(mn,x);
		updmx(mx,x);
	}
	fen.init(mx-mn+2);
	LL S=0,C=0;
	for(auto& x:a){
		x-=mn-1;
		auto [s,c]=fen.query(x);
		res+=1ll*c*x-s;
		res+=(S-s)-1ll*(C-c)*x;
		fen.add(x,{x,1});
		S+=x,++C;
	}
	dbg(res);
	return res;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<int>p(n),q(n),x(n),y(n);
	for(auto& t:p) cin>>t;
	for(auto& t:q) cin>>t;
	for(int i=0;i<n;++i){
		x[i]=p[i]+q[i];
		y[i]=p[i]-q[i];
	}
	LL ans=(work(p)+work(q))*2;
	LL sub=work(x)+work(y);
	ans-=sub;
	cout<<ans;
	return 0;
}
