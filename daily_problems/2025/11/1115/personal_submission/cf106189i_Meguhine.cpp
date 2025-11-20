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

#define N 1000005
LL sqr[N];

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	for(int i=1;i<N;++i) sqr[i]=1ll*i*i;
	ai2 G={0,0};
	auto update=[&](ai2 g)->void{
		dbg(g);
		if(!G[0]) return void(G=g);
		int ng=__gcd(G[0],g[0]);
		if(!G[1] && !g[1]) G[0]=ng;
		else if(G[1] && g[1]) G={ng,ng};
		else{
			if(!G[1]) swap(G,g);
			// now g[1]=0
			g[0]/=ng;
			if(g[0]&1) G={ng,0};
			else G={ng,ng};
		}
	};
	auto fuck=[&](int x,int y)->void{
		dbg(x,y);
		int g=__gcd(x,y);
		x/=g,y/=g;
		if(x&1 && y&1) update({g,g});
		else update({g,0});
	};
	LL n,sx,sy,w,h;
	cin>>n>>sx>>sy>>w>>h;
	bool contain_zero=(sx<=0 && sx+w>=0 && sy<=0 && sy+h>=0);
	for(int i=1;2ll*i*i<=n;++i){
		LL jj=n-1ll*i*i;
		int j=lower_bound(sqr+1,sqr+N,jj)-sqr;
		if(sqr[j]==jj) fuck(i,j);
	}
	dbg(G);
	if(!G[0]){
		cout<<contain_zero;
		return 0;
	}
	{
		LL mn=min(sx,sy);
		if(mn<0){
			LL x=(-mn-1)/G[0]+1;
			sx+=G[0]*x;
			sy+=G[0]*x;
		}
		assert(sx>=0 && sy>=0);
	}
	LL tx=sx+w,ty=sy+h;
	dbg(sx,sy,tx,ty);
	function<LL(LL,LL,ai2)>f=[&](LL x,LL y,ai2 g)->LL{
		if(x<0 || y<0) return 0;
		if(!g[1]) return (x/g[0]+1)*(y/g[0]+1);
		else{
			ai2 ng={g[0]*2,0};
			return f(x,y,ng)+f(x-g[0],y-g[0],ng);
		}
	};
	LL ans=f(tx,ty,G)-f(sx-1,ty,G)-f(tx,sy-1,G)+f(sx-1,sy-1,G);
	updmx(ans,(LL)contain_zero);
	cout<<ans;
	return 0;
}
