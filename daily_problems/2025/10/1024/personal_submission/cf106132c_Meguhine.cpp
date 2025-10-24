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

#define C const
#define ui unsigned int
#define ull unsigned long long
struct barrett{
	ui m; ull im;
	explicit barrett(ui _m):m(_m),im((ull)(-1)/_m+1){}
	ui umod() C { return m; }
	ui red(C LL& x) C {
		bool neg=0; ull ux;
		if(x<0){
			neg=1;
			if(x==LLONG_MIN) ux=0x8000000000000000ULL;
			else ux=(ull)(-x);
		}
		else ux=(ull)(x);
		ui r=redu(ux);
		if(neg){
			if(!r) return 0;
			else return m-r;
		}
		return (ui)r;
	}
	ui redu(const ull& z) C {
		ull x=(ull)(((__uint128_t)(z)*im)>>64);
		ull y=x*m;
		return (ui)(z-y+(z<y?m:0));
	}
	ui mul(ui a, ui b) C {
		ull z=a; z*=b;
		return redu(z);
	}
};
#undef ull

#define D constexpr MI
#define O operator
template<int id>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(bt.red(x)){if(v<0) v+=mod();}
	template<typename T>
	static D raw(T x){MI z; z.v=x; return z;}
	static void set_mod(ui m){bt=barrett(m);}
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){if(n&1) r*=x; x*=x; n>>=1;}
		return r;
	}
	D inv() C {return pow(mod()-2);}
	D& O +=(C MI& x){
		if((v+=x.v)>=mod()) v-=mod();
		return *this;
	}
	D& O -=(C MI& x){
		if((v-=x.v)<0) v+=mod();
		return *this;
	}
	D& O *=(C MI& x){
		v=bt.mul(v,x.v);
		return *this;
	}
	D& O /=(C MI& x){
		return *this=*this*x.inv();
	}
	int val() C{return v;}
	static ui mod(){return bt.umod();}
#define OP(s,t) friend D O s(C MI& x,C MI& y){return MI(x) t y;}
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
	static barrett bt;
};
template<int id>barrett MI<id>::bt(998244353);
#undef D
#undef C
#undef O
#undef ui

using Z=MI<0>;
#define raw(x) Z::raw(x)

#define FAIL {cout<<"NO";exit(0);}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,M,K;
	cin>>n>>M>>K;
	Z::set_mod(M);
	unordered_map<int,int>mp; int tot_mp=0;
	vector<int>key,cnt;
	for(int i=0,x,id;i<n;++i){
		cin>>x;
		auto it=mp.find(x);
		if(it!=mp.end()) id=it->second;
		else{
			cnt.emplace_back(0);
			key.emplace_back(x);
			id=mp[x]=tot_mp++;
		}
		++cnt[id];
	}
	/*
	x=p[i], y=p[i+1]
	x+y*y=k, x=k-y*y
	to[y_id]=x_id
	*/
	const int m=cnt.size();
	vector<int>to(m,-1),in(m);
	for(int i=0;i<m;++i){
		const int& y=key[i];
		int x=(raw(K)-raw(y)*raw(y)).val();
		auto it=mp.find(x);
		if(it!=mp.end()){
			const int& j=it->second;
			to[i]=j;
			++in[j];
		}
	}
	int deg0=-1;
	for(int i=0;i<m;++i){
		if(!in[i]){
			if(deg0==-1) deg0=i;
			else FAIL;
		}
	}
	auto fuck=[&](const int& st)->void{
		vector<int>p(n);
		int nw=st;
		for(int i=n-1;~i;--i){
			if(nw==-1 || --cnt[nw]<0) FAIL;
			p[i]=key[nw];
			nw=to[nw];
		}
		cout<<"YES\n";
		for(auto& x:p) cout<<x<<' ';
		exit(0);
	};
	if(deg0!=-1){
		fuck(deg0);
	}
	int mnc=*min_element(all(cnt));
	int gb=-1; // getting big
	for(int i=0;i<m;++i){
		if(cnt[i]>=mnc+2) FAIL;
		if(cnt[i]==mnc && cnt[to[i]]==mnc+1){
			if(gb==-1) gb=i;
			else FAIL;
		}
	}
	if(gb==-1) gb=0;
	else gb=to[gb];
	fuck(gb);
	return 0;
}
