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
#define PP int mid=(q[p].l+q[p].r)>>1
template<class S,auto op,auto e>
struct _SGT{ // acl-like segtree
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

namespace def{ // example: single set, range sum
	struct S{
		int sum,lmx;
	};
	S op(S a,S b){ // new s = a op b
		return S{
			a.sum+b.sum,
			max(a.lmx,a.sum+b.lmx)
		};
	}
	S e(){ // x op e() = e() op x = x
		return S{0,0};
	}
	using SGT=_SGT<S,op,e>;
};
using def::S,def::SGT;

void solve(){
	int n; cin>>n;
	vector<int>o(n+1);
	vector<vector<int>>pos(n+1);
	for(int i=1,x;i<=n;++i){
		cin>>x; o[i]=x;
		pos[x].emplace_back(i);
		pos[x].emplace_back(i+n);
	}
	vector<S>a(n*2+1);
	vector<int>L(n+1),R(n+1); // ref to index in pos
	const int base=[&]()->int {
		int res=0;
		for(int x=1;x<=n;++x){
			if(pos[x].empty()) continue;
			++res;
			if(pos[x].size()==2) continue;
			sort(all(pos[x]));
			a[pos[x][0]]=S{1,1};
			auto it=--upper_bound(all(pos[x]),n);
			a[*it]=S{-1,0};
			R[x]=it-pos[x].begin();
		}
		return res;
	}();
	SGT sgt(a,n*2);
	int ans=0;
	for(int l=1,r=n;l<=n;++l,++r){
		#ifdef LOCAL
		for(int i=1;i<=n*2;++i){
			dbg("\t",i,sgt.at(i).sum);
		}
		dbg(l,r,sgt.query(l,r).lmx);
		#endif
		updmx(ans,sgt.query(l,r).lmx);
		const int x=o[l];
		if(pos[x].size()==2) continue;
		// sgt.set(pos[x][L[x]],S{0,0}); // can be commented
		sgt.set(pos[x][R[x]++],S{0,0});
		sgt.set(pos[x][++L[x]],S{1,1});
		if(R[x]<(int)pos[x].size()){
			sgt.set(pos[x][R[x]],S{-1,0});
		}
	}
	ans+=base;
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
