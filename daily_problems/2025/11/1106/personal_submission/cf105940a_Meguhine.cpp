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

#define D constexpr MI
#define C const
#define O operator
template<int mod>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(x%mod){if(v<0) v+=mod;}
	template<typename T>
	static D raw(T x){MI z; z.v=x; return z;}
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){if(n&1) r*=x; x*=x; n>>=1;}
		return r;
	}
	D inv() C {return pow(mod-2);}
	D& O +=(C MI& x){
		if((v+=x.v)>=mod) v-=mod;
		return *this;
	}
	D& O -=(C MI& x){
		if((v-=x.v)<0) v+=mod;
		return *this;
	}
	D& O *=(C MI& x){
		LL z=v; z*=x.v; v=z%mod;
		return *this;
	}
	D& O /=(C MI& x){
		return *this=*this*x.inv();
	}
	int val() C{return v;}
#define OP(s,t) friend D O s(C MI& x,C MI& y){return MI(x) t y;}
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
};
#undef D
#undef C
#undef O

using Z=MI<(int)(1e9+7)>;
#define raw(x) Z::raw(x)

/*
0~9 => 0,0,0,1,1,1,2,2,2
c[0,1,2]
sum c[x]*(c[x]-1)/2 = 0 (mod 3)

 c*(c-1)/2 = c*(c-1)*2 = c*(c+2)*2
=(c%3)*(c%3+2)*2 (mod 3)

so... just maintain (c[0],c[1],c[2] %3)'s cnt
\
*/
inline int X(const ai4& c){
	return c[0]*27+c[1]*9+c[2]*3+c[3];
}
void solve(){
	int d; cin>>d;
	array<Z,81>dp,nw;
	auto fuck=[&](const ai3& p)->void{
		fill(all(nw),0);
		ai4 c{};
		for(c[0]=0;c[0]<3;++c[0]){
			for(c[1]=0;c[1]<3;++c[1]){
				for(c[2]=0;c[2]<3;++c[2]){
					for(c[3]=0;c[3]<3;++c[3]){
						const int xc=X(c);
						for(int x=0;x<3;++x){
							ai4 nc=c;
							nc[3]+=x;
							if(nc[3]>=3) nc[3]-=3;
							if(++nc[nc[3]]==3) nc[nc[3]]=0;
							nw[X(nc)]+=dp[xc]*raw(p[x]);
						}
					}
				}
			}
		}
		swap(dp,nw);
	};
	dp[X({1,0,0,0})]=raw(1);
	fuck({3,3,3});
	for(int i=1;i<d;++i){
		fuck({4,3,3});
	}
	ai4 c{};
	Z ans;
	for(c[0]=0;c[0]<3;++c[0]){
		int _0=c[0]*(c[0]+2);
		for(c[1]=0;c[1]<3;++c[1]){
			int _1=c[1]*(c[1]+2);
			for(c[2]=0;c[2]<3;++c[2]){
				int _2=c[2]*(c[2]+2);
				int s=(_0+_1+_2)*2%3;
				if(s) continue;
				for(c[3]=0;c[3]<3;++c[3]){
					ans+=dp[X(c)];
				}
			}
		}
	}
	cout<<ans.val()<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
