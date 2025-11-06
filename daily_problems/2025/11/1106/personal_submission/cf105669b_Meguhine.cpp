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

template<int mod>
LL fuck(const string& s){
	LL x=0;
	for(auto& c:s){
		x=x*10+c-'0';
		x%=mod;
	}
	return x;
}

template<int mod>
LL ksm(LL a,LL b){
	LL r=1;
	while(b){
		if(b&1) r=r*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return r;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	constexpr int mod=(int)(1e9+7);
	string a,op,b;
	cin>>a>>op>>b;
	LL x=fuck<mod>(a),y;
	if(op[0]=='^') y=fuck<mod-1>(b);
	else y=fuck<mod>(b);
	if(op[0]=='+') x=(x+y)%mod;
	else if(op[0]=='-') x=(x+mod-y)%mod;
	else if(op[0]=='*') x=(x*y)%mod;
	else x=ksm<mod>(x,y);
	cout<<x;
	return 0;
}
