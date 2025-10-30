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

using Z=MI<998244353>;
#define raw(x) Z::raw(x)

/*
square: a*a
m := (n-a*a)/2
dp[a][m], put m blocks on len a.
look at top left part,
we put blocks from bottom to top.
init: dp[1][any]=dp[any][0]=1
dp[a][m]=sum_{1<=b<=min(a,m)}(dp[b][m-b])
optimize: sum[x]=sum(dp[i][x-i])
*/
constexpr int N=200005;
constexpr int M=sqrt(N)+1;
Z dp[M][N];
void init(){
	for(int i=1;i<N;++i){
		dp[1][i]=raw(1);
	}
	for(int i=1;i<M;++i){
		dp[i][0]=dp[i][1]=raw(1);
	}
	for(int m=2;m<N;++m){
		Z sum=raw(1); // dp[1][m-1];
		for(int a=2;a<M;++a){
			if(a<=m) sum+=dp[a][m-a];
			dp[a][m]=sum;
		}
	}
}
void solve(){
	int n; cin>>n;
	Z ans;
	for(int a=1;a*a<=n;++a){
		int m=n-a*a;
		if(m&1) continue;
		m>>=1;
		ans+=dp[a][m];
		dbg(a,m,dp[a][m].val());
	}
	dbg(ans.val());
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
