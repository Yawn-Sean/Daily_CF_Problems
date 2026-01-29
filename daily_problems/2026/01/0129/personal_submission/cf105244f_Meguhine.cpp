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

constexpr int N=1005;
int f[N]; // f[x] is min steps to achieve x

bool init_f=[](){
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for(int i=1;i<N;++i){
		for(int l=1;l<=i;){
			const int x=i/l;
			const int j=i+x;
			if(j<N) updmn(f[j],f[i]+1);
			l=i/x+1;
		}
	}
	return true;
}();

int b[N],dp[N*12];

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	// dbg(ranges::max(f|views::drop(1)));  // 12
	int n,m; cin>>n>>m;
	int tot=0;
	for(int i=0,x;i<n;++i){
		cin>>x;
		tot+=(b[i]=f[x]);
	}
	updmn(tot,m);
	for(int i=0,y;i<n;++i){
		const int x=b[i];
		cin>>y;
		for(int j=tot;j>=x;--j){
			updmx(dp[j],dp[j-x]+y);
		}
	}
	cout<<ranges::max(dp);
	return 0;
}
