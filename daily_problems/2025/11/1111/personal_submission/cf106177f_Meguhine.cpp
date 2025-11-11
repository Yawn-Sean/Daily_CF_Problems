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
f(x)=
- x-2 if x is even
- x+2 if x is odd

x*f(odd)+y*f(even) -> 2(x-y)
f(x odd, y even) ->
- x is odd, total odd, +2
- x is even, total even, -2

thus, x odd -> y=x-1, x-y=1
x even -> y=x+1, x-y=-1
fuck this then.
*/
void solve(){
	int n,s=0,o=0; cin>>n;
	vector<int>_o(n*2+6),_z(n*2+6);
	const int base=n+3;
	_z[base]=1;
	LL ans=0;
	for(int x;n--;){
		cin>>x;
		if(x&1) ++s,o^=1;
		else --s;
		if(o){
			++_o[s+base];
			ans+=_z[s+base-1];
			ans+=_o[s+base+1];
		}
		else{
			++_z[s+base];
			ans+=_o[s+base-1];
			ans+=_z[s+base+1];
		}
	}
	dbg(ans);
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
