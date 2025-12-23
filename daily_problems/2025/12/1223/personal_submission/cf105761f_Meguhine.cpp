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
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

int guess(int n,int m){
	if(n==1) return 0;
	if(m==1) return n-1;
	return 1+max(guess(n/2,m-1),guess(n-n/2,m));
}

constexpr int inf=1e9;
void solve(){
	int n,m;
#ifndef LOCAL
	cin>>n>>m;
#else
	n=rand(1,10000);
	m=rand(1,20);
#endif
	updmn(m,20);
	vector dp(m+1,vector<int>(n+1,1));
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
			updmn(dp[i][j],inf);
		}
	}
	// #ifdef LOCAL
	// for(int i=1;i<=m;++i){
	// 	for(int j=1;j<=n;++j){
	// 		dbg(i,j,dp[i][j]);
	// 	}
	// }
	// #endif
	// note when n=1, ans=0, so iterate from i=0
	for(int i=0;i<=n;++i){
		if(dp[m][i]>=n){
			cout<<i<<'\n';
			#ifdef LOCAL
			dbg(n,m,i);
			dbg(guess(n,m));
			assert(i==guess(n,m));
			#endif
			return;
		}
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
#else
	int t=1000;
	while(t--) solve();
#endif
	return 0;
}
