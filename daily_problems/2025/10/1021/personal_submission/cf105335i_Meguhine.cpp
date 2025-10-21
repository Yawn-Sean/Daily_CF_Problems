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
  	int kth(T k){
		int ans=0,cnt=0;
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

void p2m(const vector<int>& a,const int& n,vector<int>& b){
	Fenwick<int>fen(n+1);
	b.resize(n+1);
	for(int i=n;i>0;--i){
		b[i]=fen.query(a[i]);
		fen.add(a[i],1);
	}
}
LL m2id(const vector<int>& b,const int& n){
	LL res=0,base=1;
	for(int i=n-1;i>0;--i){
		base*=(n-i);
		res+=b[i]*base;
	}
	return res;
}
void m2p(const vector<int>& b,const int& n,vector<int>& a){
	a.resize(n+1);
	Fenwick<int>fen(n+1);
	for(int i=1;i<=n;++i){
		fen.add(i,1);
	}
	for(int i=1,x;i<n;++i){
		x=fen.kth(b[i]+1);
		a[i]=x;
		fen.add(x,-1);
	}
	a[n]=fen.kth(1);
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<int>a(n+1),b;
	for(int i=1;i<=n;++i) cin>>a[i];
	p2m(a,n,b);
	if(n&1){
		bool _=0;
		b[2]+=(n/2);
		if(b[2]>=n-1){
			b[2]-=(n-1);
			_=1;
		}
		b[1]+=(n/2)+_;
		if(b[1]>=n){
			b[1]-=n;
		}
	}
	else{
		b[1]+=(n/2);
		if(b[1]>=n){
			b[1]-=n;
		}
	}
	m2p(b,n,a);
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
	return 0;
}
