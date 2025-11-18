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

#define ls (p<<1)
#define rs (p<<1|1)
template<class S,auto op,auto e>
struct _SGT{ // acl-like lazy_segtree
private:
	struct Node{ int l,r; S s; };
	vector<Node>q;
	void pull(int p){ q[p].s=op(q[ls].s,q[rs].s); }
	void build(const vector<S>& a,int l,int r,int p=1){
		q[p].l=l,q[p].r=r;
		if(l==r) return (void)(q[p].s=a[l]);
		int mid=(l+r)>>1;
		build(a,l,mid,ls);
		build(a,mid+1,r,rs);
		pull(p);
	}
	template<class F>
	int _minl(int r,F f,S& s,int p){
		if(q[p].r==r){
			S ns=op(q[p].s,s);
			if(f(ns)) return s=ns,q[p].l;
		}
		if(q[p].l==q[p].r) return q[p].l+1;
		int mid=(q[p].l+q[p].r)>>1;
		if(r<=mid) return _minl(r,f,s,ls);
		else{
			int res=_minl(r,f,s,rs);
			if(res>mid+1) return res;
			else return _minl(mid,f,s,ls);
		}
	}
	template<class F>
	int _maxr(int l,F f,S& s,int p){
		if(q[p].l==l){
			S ns=op(s,q[p].s);
			if(f(ns)) return s=ns,q[p].r;
		}
		if(q[p].l==q[p].r) return q[p].r-1;
		int mid=(q[p].l+q[p].r)>>1;
		if(l>mid) return _maxr(l,f,s,rs);
		else{
			int res=_maxr(l,f,s,ls);
			if(res<mid) return res;
			else return _maxr(mid+1,f,s,rs);
		}
	}
public:
	_SGT(int n){ init(n); }
	_SGT(const vector<S>& a,int n){ init(a,n); }
	void init(int n){ init(vector<S>(n+1,e()),n); }
	void init(const vector<S>& a,int n){ q.resize(n*4+10); build(a,1,n); }
	S query(int l,int r,int p=1){
		if(q[p].l==l && q[p].r==r) return q[p].s;
		int mid=(q[p].l+q[p].r)>>1;
		if(r<=mid) return query(l,r,ls);
		else if(l>mid) return query(l,r,rs);
		else return op(query(l,mid,ls),query(mid+1,r,rs));
	}
	void set(int x,S s,int p=1){
		if(q[p].l==q[p].r) return (void)(q[p].s=s);
		int mid=(q[p].l+q[p].r)>>1;
		if(x<=mid) set(x,s,ls);
		else set(x,s,rs);
		pull(p);
	}
	S at(int x,int p=1){
		if(q[p].l==q[p].r) return q[p].s;
		int mid=(q[p].l+q[p].r)>>1;
		if(x<=mid) return at(x,ls);
		else return at(x,rs);
	}
	template<auto f>
	int min_left(int r){ return min_left<decltype(f)>(r,f); }
	template<class F>
	int min_left(int r,F f){
		if(r<1 || r>q[1].r) return -1;
		S s=e(); return max(1,_minl(r,f,s,1));
	}
	template<auto f>
	int max_right(int l){ return max_right<decltype(f)>(l,f); }
	template<class F>
	int max_right(int l,F f){
		if(l<1 || l>q[1].r) return -1;
		S s=e(); return min(q[1].r,_maxr(l,f,s,1));
	}
};
#undef ls
#undef rs

namespace def{ // example: single set, range sum
	using S=int;
	S op(S a,S b){ // new s = a op b
		return min(a,b);
	}
	S e(){ // x op e() = e() op x = x
		return INT_MAX;
	}
	using SGT=_SGT<S,op,e>;
};
using def::SGT;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,Q;
	cin>>n>>Q;
	vector<int>R(n+1,0);
	SGT sgt(R,n);
	for(int op,l,r;Q--;){
		cin>>op>>l;
		if(op==1){
			cin>>r;
			if(updmx(R[l],r)) sgt.set(l,r);
		}
		else{
			auto f=[&](def::S s)->bool{
				return s>=l;
			};
			int res=sgt.min_left(l,f);
			cout<<(l-res+2)<<'\n';
		}
	}
	return 0;
}
