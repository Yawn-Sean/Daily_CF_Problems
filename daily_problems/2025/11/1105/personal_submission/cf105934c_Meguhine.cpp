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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	auto fuck=[&](bool f)->LL{
		LL res=0;
		int last=a[0],nw;
		for(int i=1;i<n;++i){
			nw=a[i];
			if(f){
				if(nw<=last){
					res+=last-nw+1;
					nw=last+1;
				}
			}
			else{
				if(nw>=last){
					res+=nw-last+1;
					nw=last-1;
				}
			}
			f^=1;
			last=nw;
		}
		return res;
	};
	LL ans=min(fuck(0),fuck(1));
	cout<<ans;
	return 0;
}
