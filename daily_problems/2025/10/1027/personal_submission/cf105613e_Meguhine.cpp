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
min n, n(n-1)/2>=m
n(n-1)/2-(n-1)(n-2)/2=n-1
needs to sub: [1,n-2]
so just, some 6, one 2, #(n-2) of 3
other numbers, (base+5)+6i, (base+9)+6i
*/
constexpr int base=500000;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	if(1ll*n*(n-1)<m*2){
		cout<<"-1";
		return 0;
	}
	if(!m){
		for(int i=1;i<=n;++i){
			cout<<(base+i)<<' ';
		}
		return 0;
	}
	int nn=sqrt(m*2);
	while(1ll*nn*(nn-1)<m*2) ++nn;
	cout<<"6 2";
	int sub=1ll*nn*(nn-1)/2-m;
	for(int i=0;i<sub;++i) cout<<" 3";
	for(int i=sub+2;i<nn;++i) cout<<" 6";
	int x=base+5; bool f=0;
	for(int i=nn;i<n;++i){
		cout<<' '<<x;
		if(f) x+=2;
		else x+=4;
		f^=1;
	}
	return 0;
}
