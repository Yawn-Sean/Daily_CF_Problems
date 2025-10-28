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

constexpr int N=1024;
bitset<N>a;
int main(){
	int n; scanf("%d",&n);
	while(1){
		int mn=0,mni=0,nw=0;
		int rua=-1,l=-1,r=-1;
		for(int i=1;i<=n;++i){
			if(a[i]) --nw;
			else ++nw;
			if(updmn(mn,nw)) mni=i;
			if(updmx(rua,nw-mn)){
				l=mni+1,r=i;
			}
		}
//		assert(l!=-1 && r!=-1);
		printf("%d %d\n",l,r);
		fflush(stdout);
		for(int i=1,x;i<=n;++i){
			scanf("%d",&x);
			if(x) a.set(i);
			else a.reset(i);
		}
		int x; scanf("%d",&x);
		if(x>=70) break;
	}
	return 0;
}
