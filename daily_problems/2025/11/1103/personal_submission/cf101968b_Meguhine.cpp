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

#define D constexpr MI
#define C const
#define O operator
template<int mod>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(x%mod){if(v<0) v+=mod;}
	template<typename T>
	static D raw(T x){MI z; z.v=x; return z;}
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){if(n&1) r*=x; x*=x; n>>=1;}
		return r;
	}
	D inv() C {return pow(mod-2);}
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
	D& O /=(C MI& x){
		return *this=*this*x.inv();
	}
	int val() C{return v;}
#define OP(s,t) friend D O s(C MI& x,C MI& y){return MI(x) t y;}
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
};
#undef D
#undef C
#undef O

using Z=MI<(int)(1e9+7)>;
#define raw(x) Z::raw(x)

constexpr int N=1e5+5;
Z fc[N];
void init(){
	fc[0]=fc[1]=raw(1);
	for(int i=2;i<N;++i){
		fc[i]=fc[i-1]*raw(i);
	}
}
void solve(){
	int m; cin>>m;
	const int n=m*2;
	vector<int>X(n),Y(n);
	vector<ai2>a(n);
	for(int i=0;i<n;++i){
		cin>>X[i]>>Y[i];
		a[i]={X[i],Y[i]};
	}
	nth_element(X.begin(),X.begin()+m,X.end());
	const int xmid=X[m];
	nth_element(Y.begin(),Y.begin()+m,Y.end());
	const int ymid=Y[m];
	ai4 c{};
	for(auto& [x,y]:a){
		int mask=((int)(x>=xmid)<<1)|(y>=ymid);
		++c[mask];
	}
	dbg(xmid,ymid,c);
	if(c[0]!=c[3] || c[1]!=c[2]) return (void)(cout<<"0\n");
	Z ans=fc[c[0]]*fc[c[1]];
	cout<<ans.val()<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
