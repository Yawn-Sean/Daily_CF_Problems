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

constexpr int P=22;
constexpr int M=1<<P;
bitset<M>ok[P],dp;

#define bitset_or(x,y) ((x)=(x)|(y))

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	{
		int n; cin>>n;
		for(int i=0;i<n;++i){
			int x; cin>>x;
			int high=__lg(x);
			ok[high][(~x)&((1<<high)-1)]=1;
			dbg(x,high,((~x)&((1<<high)-1)));
		}
	}
	for(int high=1;high<P;++high){
		dbg(high);
		for(int mask=(1<<high)-1;~mask;--mask){
			dbg("\t",mask,ok[high][mask]);
			for(int i=0;i<high;++i) if(mask>>i&1){
				bitset_or(ok[high][mask^(1<<i)],ok[high][mask]);
			}
		}
	}
	int ans=0;
	dp[0]=1;
	for(int mask=0;mask<M;++mask){
		if(!dp[mask]) continue;
		updmx(ans,__builtin_popcount(mask));
		for(int i=mask?(__lg(mask)+1):0;i<P;++i){
			if(ok[i][mask]) dp[mask|(1<<i)]=1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
