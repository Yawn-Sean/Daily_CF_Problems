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
i people, each j balloons.
next person brings x balloons,
avg becomes (j+k) balloons.
ij+x=(i+1)(j+k)
x=ik+j+k=(i+1)k+j
since 1<=x<=K
suitable k will gradually range thinner.
so just brute force
*/

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,K; cin>>n>>K;
	updmn(n,K+1);
	vector<Z>dp(K+1,raw(1)),nw(K+1);
	dp[0]=raw(0);
	for(int i=2;i<=n;++i){
		nw.assign(K+1,raw(0));
		for(int j=1;j<=K;++j){
			/*
			1 <= ik+j <= K
			1-j <= ik <= K-j
			(1-j)/i <= k <= (K-j)/i
			*/
			for(int k=(1-j)/i-1;k<=(K-j)/i;++k){
				const int x=i*k+j;
				if(1<=x && x<=K){
					nw[j+k]+=dp[j];
				}
			}
		}
		swap(dp,nw);
	}
	cout<<accumulate(all(dp),raw(0)).val();
	return 0;
}
