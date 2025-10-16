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

constexpr int N=17;
constexpr int inf=1e9;

int C(int n,int m,int x){
	// m <= n-m
	LL r=n;
	for(int i=2;i<=m;++i){
		r=r*(n-i+1)/i;
		if(r>x) return 0;
	}
	return (int)r;
}

int c[N][2000],R[N];
void init(){
	// C(34,17)>1e9
	for(int m=3;m<N;++m){
		int i=m*2;
		while(1){
			int r=C(i,m,inf);
			if(!r){
				R[m]=i;
				break;
			}
			c[m][i++]=r;
		}
		dbg(R[m],m,C(R[m],m,inf));
	}
}
void solve(){
	int n; cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	int ans=n+1;
	{
		// m=2
		int x=sqrt(n*2);
		while(1ll*x*(x-1)<=n*2) ++x;
		if(1ll*(x-1)*(x-2)==n*2) updmn(ans,x);
	}
	for(int m=3;m<N;++m){
		int i=upper_bound(c[m]+m*2,c[m]+R[m],n)-c[m];
		if(c[m][i-1]==n) updmn(ans,i);
	}
	cout<<ans<<'\n';
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
