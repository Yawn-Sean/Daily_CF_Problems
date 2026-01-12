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

constexpr int N=205;
constexpr int M=1e5+5;
struct Node{
	int a,b,c;
	friend bool operator <(const Node& x,const Node& y){
		return 1ll*y.b*(x.a-1)<1ll*x.b*(y.a-1);
	}
}a[N];
int n,m;

int dp[N][M];

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a+1,a+n+1);
#ifdef LOCAL
	for(int i=1;i<=n;++i) dbg(a[i].a,a[i].b,a[i].c);
#endif
	for(int i=1;i<=n;++i){
		for(int j=0;j<a[i].b;++j){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=a[i].b;j<=m;++j){
			dp[i][j]=dp[i-1][j];
			const int nj=(j-a[i].b)/a[i].a;
			updmx(dp[i][nj],dp[i-1][j]+a[i].c);
		}
	}
	int ans=0;
	for(int j=0;j<=m;++j){
		updmx(ans,dp[n][j]);
	}
	cout<<ans;
	return 0;
}
