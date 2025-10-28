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

constexpr int N=10005;
using B=bitset<N>;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,L,R;
	cin>>n>>L>>R;
	vector<ai2>a(n);
	for(auto& [m,c]:a) cin>>m>>c;
	vector<int>b;
	B dp;
	auto check=[&](const int& lim)->bool{
		b.clear();
		for(auto [m,c]:a){
			c/=lim;
			int x=1;
			while(x<=c){
				LL y=1ll*x*m;
				if(y>R) break;
				b.emplace_back(y);
				c-=x;
				x<<=1;
			}
			if(c){
				LL y=1ll*c*m;
				if(y<=R) b.emplace_back(y);
			}
		}
		dp.reset(); dp[0]=1;
		for(auto& x:b){
			dp|=(dp<<x);
		}
		for(int i=L;i<=R;++i){
			if(dp[i]) return 1;
		}
		return 0;
	};
	int l=1,r=1e6,mid,ans=0;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
