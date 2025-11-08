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

constexpr LL inf=4e18;
using big=__int128_t;

using al2=array<LL,2>;
vector<al2>a;

void init(){
	a={{1,9}};
	LL l=10,r=99;
	while(l<(LL)(1e18)){
		a.push_back({l,r});
		l=l*10;
		r=r*10+9;
	}
	a.push_back({(LL)(1e18),(LL)(9e18)});
}
LL calc(const LL& st,const LL& n){
	const LL ed=st+n-1;
	big res=0;
	for(int i=0;i<a.size();++i){
		LL l=max(st,a[i][0]);
		LL r=min(ed,a[i][1]);
		if(l>r) continue;
		res+=(big)(r-l+1)*(i+1);
	}
	if(res>=inf) return inf;
	dbg(st,n,(LL)res);
	return (LL)res;
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init();
	LL n,m;
	cin>>n>>m;
	LL l=1,r=inf,mid,ans=inf;
	while(l<=r){
		mid=l+r>>1;
		LL x=calc(mid,n);
		if(x==m) updmn(ans,mid);
		if(x>=m) r=mid-1;
		else l=mid+1;
	}
	if(ans==inf) ans=-1;
	cout<<ans;
	return 0;
}
