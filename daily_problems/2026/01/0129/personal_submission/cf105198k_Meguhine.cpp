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

#define D constexpr MI
#define C const
#define O operator
template<unsigned int mod>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(x%mod){ if(v<0) v+=mod; }
	template<typename T>
	static D raw(T x){ MI z; z.v=x; return z; }
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){ if(n&1) r*=x; x*=x; n>>=1; }
		return r;
	}
	D inv() C { return pow(mod-2); }
	D& O +=(C MI& x){
		if((v+=x.v)>=mod) v-=mod;
		return *this;
	}
	D& O -=(C MI& x){
		if((v-=x.v)<0) v+=mod;
		return *this;
	}
	D& O *=(C MI& x){
		LL z=v; z*=x.v; v=z%mod;
		return *this;
	}
	D& O /=(C MI& x){ return *this=*this*x.inv(); }
	int val() C { return v; }
	static constexpr unsigned int umod(){ return mod; }
#define OP(s,t) friend D O s(C MI& x,C MI& y){ return MI(x) t y; }
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
};
#undef D
#undef C
#undef O

using Z=MI<int(1e9+7)>;
#define raw(x) Z::raw(x)

namespace Fac{ // factorial
	constexpr int N=2e6+5;
	Z fc[N],fc_inv[N];
	void init(){
		fc[0]=fc_inv[0]=raw(1);
		for(int i=1;i<N;i++){
			fc[i]=fc[i-1]*raw(i);
		}
		fc_inv[N-1]=fc[N-1].inv();
		for(int i=N-2;i>0;i--){
			fc_inv[i]=fc_inv[i+1]*raw(i+1);
		}
	}
	Z P(const int x,const int y){
		return fc[x]*fc_inv[x-y];
	}
	Z C(const int x,const int y){
		if(x==y) return raw(1);
		if(x<0 || y<0 || x-y<0) return raw(0);
		return fc[x]*fc_inv[y]*fc_inv[x-y];
	}
}

/*
L: x-1
M: g-(x-1)-(y-1) as a single element
R: y-1
*/

void solve(){
	int b,g,x,y;
	cin>>b>>g>>x>>y;
	if(x+y>g){
		cout<<"0\n";
		return;
	}
	Z tot=Fac::C(b+g,b);
	Z sub=Fac::C(b+x+y-1,b);
	cout<<(tot-sub).val()<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	Fac::init();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
