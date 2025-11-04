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
one operation:
- a--
- b--
- a++, b--

b=0, win if a is odd
b=1, always win
b=2, no one would del b first (else that guy lose)
	so a should be odd to not del b first.
b=3, del 1 b to make a even, so always win.
...
so if a&1 or b&1, win.
*/
void solve(){
	int T; cin>>T;
	int a=0,b=0;
	for(string s;T--;){
		cin>>s;
		if(s[0]=='=') s=s.substr(3);
		if(s[0]=='x' && s[2]=='x'){
			if(s[1]=='x') ++b;
		}
		else{
			if(s[0]=='x' || s[2]=='x') ++a;
		}
	}
	if((a&1) || (b&1)) cout<<"Monocarp\n";
	else cout<<"Polycarp\n";
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
