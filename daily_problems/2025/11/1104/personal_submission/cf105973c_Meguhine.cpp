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

/*
XOR_{i=1}^{n} XOR_{j=1}^{i} C(i,j)
XOR_{j=1}^{i} C(i,j):
- i is odd, 1
- i is even, 1 xor C(i,i/2)
easy problem
*/

const int mod=998244353;
LL ksm(LL a,LL b){
	a%=mod; LL ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

constexpr int N=1e6+5;
namespace Fac{ // factorial
	LL fc[N],fc_inv[N];
	void init(){
		fc[0]=fc_inv[0]=1;
		for(int i=1;i<N;i++){
			fc[i]=fc[i-1]*i%mod;
		}
		fc_inv[N-1]=ksm(fc[N-1],mod-2);
		for(int i=N-2;i>0;i--){
			fc_inv[i]=fc_inv[i+1]*(i+1)%mod;
		}
	}
	LL F(const int& x){
		return fc[x];
	}
	LL P(const int& x,const int& y){
		return fc[x]*fc_inv[x-y]%mod;
	}
	LL C(const int& x,const int& y){
		if(x==y) return 1;
		if(x<0 || y<0 || x-y<0) return 0;
		return fc[x]*fc_inv[y]%mod*fc_inv[x-y]%mod;
	}
}

LL ans[N];
void init(){
	ans[1]=1;
	for(int i=2;i<N;++i){
		ans[i]=ans[i-1]^1;
		if(!(i&1)){
			ans[i]^=Fac::C(i,i/2);
		}
	}
}
void solve(){
	int n; cin>>n;
	cout<<ans[n]<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	Fac::init();
	init();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
