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
work(a,b):
a=(b/i)+(b/j)
a/b=1/i+1/j, i,j>=1
a/b<=2
a<=2b, b<=2a
0.5b<=a<=2b
1/2 <= a/b <= 2
suppose 1/i < 1/j
1/j < a/b <= 2/j
1 < aj/b <= 2
1/(a/b) < j <= 2/(a/b)
1/2 < j <= 4
so iterate j over 1~4.
*/

bool check(LL a,LL b){
	for(int j=1;j<=4;++j){
		if(b%j) continue;
		LL b_i=a-b/j;
		if(b_i>0 && b%b_i==0) return 1;
	}
	return 0;
}
void solve(){
	LL a,b;
	cin>>a>>b;
	if(a>b*2 || b>a*2) cout<<"NO\n";
	else if(check(a,b) && check(b,a)){
		cout<<"SI\n";
	}
	else cout<<"NO\n";
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
