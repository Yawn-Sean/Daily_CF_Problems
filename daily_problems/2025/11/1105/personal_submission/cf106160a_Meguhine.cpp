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
consider each digits separately
[+/-]*d*10^[x]

[+/-]: trivial dp
	pos[i]=pos[i-1]*0.1+0.45
	neg[i]=neg[i-1]*0.1+0.45
init: pos[0]=1, neg[0]=0

[x]: 10^x is not linear,
thus need to calc E(10^x)
first calc P(x=k)
P(x=0)=0.9
P(x=1)=0.1*0.9
P(x=2)=(0.1)^2*0.9
etc.
E(10^x)=do trvial calc.
if move to prev digit:
En(10^x)=(10^0)*0.9+E(10^x)*10*0.1
		=0.9+E(10^x)
wow, that's not convergent !!
E_i(10^x)=E_{i+1}(10^x)+0.9
init: E_n(10^x)=1
*/
using LD=long double;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	string s; cin>>s;
	const int& n=s.size();
	LD ans=LD(0.0),pos=LD(1.0),neg=LD(0.0);
	LD ep=LD(1.0)+LD(0.9)*(n-1);
	for(int i=1;i<=n;++i){
		ans+=(pos-neg)*(s[i-1]-'0')*ep;
		pos=pos*0.1+LD(0.45);
		neg=neg*0.1+LD(0.45);
		ep-=LD(0.9);
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}
