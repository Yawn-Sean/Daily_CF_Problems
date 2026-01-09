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

#define ls (p<<1)
#define rs (p<<1|1)
#define PP push(p); int mid=(q[p].l+q[p].r)>>1
template<class S,auto op,auto e,class F,auto mp,auto comp,auto id>
struct _SGT{ // acl-like lazy_segtree
private:
	struct Node{ int l,r; S s; F f; };
	vector<Node>q;
	void update(int p,const F& f){
		Node& u=q[p]; u.s=mp(f,u.s);
		if(u.l!=u.r){
			u.f=comp(f,u.f);
//			if(u.s.fail) push(p),pull(p);
		}
//		else assert(!u.s.fail);
	}
	void push(int p){
		if(q[p].l==q[p].r) return;
		update(ls,q[p].f);
		update(rs,q[p].f);
		q[p].f=id();
	}
	void pull(int p){ q[p].s=op(q[ls].s,q[rs].s); }
	void build(const vector<S>& a,int l,int r,int p=1){
		q[p].l=l,q[p].r=r,q[p].f=id();
		if(l==r) return (void)(q[p].s=a[l]);
		int mid=(l+r)>>1;
		build(a,l,mid,ls);
		build(a,mid+1,r,rs);
		pull(p);
	}
	template<class G>
	int _minl(int r,G g,S& s,int p=1){
		if(q[p].r==r){
			S ns=op(q[p].s,s);
			if(g(ns)) return s=ns,q[p].l;
		}
		if(q[p].l==q[p].r) return q[p].l+1;
		PP;
		if(r<=mid) return _minl(r,g,s,ls);
		else{
			int res=_minl(r,g,s,rs);
			if(res>mid+1) return res;
			else return _minl(mid,g,s,ls);
		}
	}
	template<class G>
	int _maxr(int l,G g,S& s,int p=1){
		if(q[p].l==l){
			S ns=op(s,q[p].s);
			if(g(ns)) return s=ns,q[p].r;
		}
		if(q[p].l==q[p].r) return q[p].r-1;
		PP;
		if(l>mid) return _maxr(l,g,s,rs);
		else{
			int res=_maxr(l,g,s,ls);
			if(res<mid) return res;
			else return _maxr(mid+1,g,s,rs);
		}
	}
public:
	_SGT(int n){ init(n); }
	_SGT(const vector<S>& a,int n){ init(a,n); }
	void init(int n){ init(vector<S>(n+1,e()),n); }
	void init(const vector<S>& a,int n){ q.resize(n*4+10); build(a,1,n); }
	void modify(int l,int r,const F& f,int p=1){
		if(q[p].l==l && q[p].r==r) return (void)(update(p,f));
		PP;
		if(r<=mid) modify(l,r,f,ls);
		else if(l>mid) modify(l,r,f,rs);
		else modify(l,mid,f,ls),modify(mid+1,r,f,rs);
		pull(p);
	}
	S query(int l,int r,int p=1){
		if(q[p].l==l && q[p].r==r) return q[p].s;
		PP;
		if(r<=mid) return query(l,r,ls);
		else if(l>mid) return query(l,r,rs);
		else return op(query(l,mid,ls),query(mid+1,r,rs));
	}
	void set(int x,S s,int p=1){
		if(q[p].l==q[p].r) return (void)(q[p].s=s);
		PP;
		if(x<=mid) set(x,s,ls);
		else set(x,s,rs);
		pull(p);
	}
	S at(int x,int p=1){
		if(q[p].l==q[p].r) return q[p].s;
		PP;
		if(x<=mid) return at(x,ls);
		else return at(x,rs);
	}
	template<auto g>
	int min_left(int r){ return min_left<decltype(g)>(r,g); }
	template<class G>
	int min_left(int r,G g){
		assert(q[1].l<=r && r<=q[1].r);
		S s=e(); return max(q[1].l,_minl(r,g,s));
	}
	template<auto g>
	int max_right(int l){ return max_right<decltype(g)>(l,g); }
	template<class G>
	int max_right(int l,G g){
		assert(q[1].l<=l && l<=q[1].r);
		S s=e(); return min(q[1].r,_maxr(l,g,s));
	}
};
#undef PP
#undef ls
#undef rs

namespace def{ // example: range add, range sum
	struct S{
		LL s; // sum
		int l; // len
	};
	S op(S a,S b){ // new s = a op b
		return S{a.s+b.s,a.l+b.l};
	}
	S e(){ // x op e() = e() op x = x
		return S{0,0};
	}
	using F=LL;
	S mapping(F f,S x){ // x -> f(x)
		return S{x.s+f*x.l,x.l};
	}
	F composition(F f,F g){ // f(g(x))
		return f+g;
	}
	F id(){ // id(x) = x
		return 0;
	}
	using SGT=_SGT<S,op,e,F,mapping,composition,id>;
};
using def::S,def::F,def::SGT;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,Q; cin>>n>>Q;
	vector<S>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i].s;
		a[i].l=1;
	}
	set<int>ans;
	{
		vector<LL>s(n+1);
		for(int i=1;i<n;++i){
			s[i]=s[i-1]+a[i].s;
			if(s[i]<=a[i+1].s) ans.insert(i+1);
		}
	}
	SGT sgt(a,n);
	for(int l,r,x;Q--;){
		cin>>l>>r>>x;
		if(l!=1) ans.insert(l);
		sgt.modify(l,r,x);
		x=-1;
		while(ans.size()){
			const int p=*ans.begin();
			if(sgt.query(1,p-1).s<=sgt.at(p).s){
				x=p;
				break;
			}
			ans.erase(ans.begin());
		}
		cout<<x<<'\n';
	}
	return 0;
}
