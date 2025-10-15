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
define m = local maxima
between 2 m, assume x number(s) (include 2 m)
there are x ways to divide:
- x-1 ways to choose a gap to divide
- 1 way to not divide
thus, ans = PI x
*/

constexpr int mod=1e9+7;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	int l,p=0; cin>>l;
	LL ans=1;
	for(int i=1,x;i<n;++i){
		cin>>x;
		if(x>l){
			ans=ans*(i-p+1)%mod;
			l=x,p=i;
		}
	}
	cout<<ans;
	return 0;
}
