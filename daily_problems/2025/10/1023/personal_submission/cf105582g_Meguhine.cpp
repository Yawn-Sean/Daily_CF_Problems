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

/*
(m0+m1)/(t0+t1)=a/b
b(m0+m1)=a(t0+t1)
-a*t0+b*m0=a*t1-b*m1
*/
using M=unordered_map<LL,int>;
void fuck(auto&& o,int a,int b,M& mp){
	const int& n=o.size();
	for(int s=0;s<(1<<n);++s){
		LL m=0,t=0;
		for(int i=0;i<n;++i){
			if(s>>i&1){
				m+=o[i][0];
				t+=o[i][1];
			}
		}
		++mp[t*a+m*b];
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,a,b;
	cin>>n>>a>>b;
	vector<ai2>x(n/2),y(n-n/2);
	for(auto& [m,t]:x) cin>>m>>t;
	for(auto& [m,t]:y) cin>>m>>t;
	M mx,my;
	fuck(x,-a,b,mx);
	fuck(y,a,-b,my);
	LL ans=-1;
	for(auto& [v,c]:mx){
		auto it=my.find(v);
		if(it!=my.end()){
			ans+=1ll*c*it->second;
		}
	}
	cout<<ans;
	return 0;
}
