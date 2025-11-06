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
sort and divide.
m := ceil(n/3)
a[0]~a[m-1] a[m]~a[m*2-1] a[m*2]~a[n-1]
last:
a[n-1-i] = (a[n-1-i]-i) + i
second:
a[i] = 0 + **a[i]** (a[i] won't overlap with last seg)
first:
a[i] = **i** + (a[i]-i) (i won't overlap with last seg)
*/
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	cout<<"YES\n";
	int n; cin>>n;
	if(n<3){
		vector<int>a(n);
		for(auto& x:a) cin>>x;
		for(int i=0;i<n;++i) cout<<"0 ";
		cout<<'\n';
		for(auto& x:a) cout<<x<<' ';
		return 0;
	}
	vector<ai2>a(n);
	for(int i=0;i<n;++i){
		cin>>a[i][0];
		a[i][1]=i;
	}
	sort(all(a));
	const int m=(n-1)/3+1;
	vector<int>b(n),c(n);
	for(int i=0;i<m;++i){
		auto& [x,p]=a[i];
		b[p]=i,c[p]=x-i;
	}
	for(int i=m;i<m*2;++i){
		auto& [x,p]=a[i];
		b[p]=0,c[p]=x;
	}
	for(int i=n-1,j;i>=m*2;--i,++j){
		auto& [x,p]=a[i];
		b[p]=x-j,c[p]=j;
	}
	for(auto& x:b) cout<<x<<' ';
	cout<<'\n';
	for(auto& x:c) cout<<x<<' ';
	return 0;
}
