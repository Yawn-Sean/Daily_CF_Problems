/*
感觉题目描述有歧义啊，通过铲子挖的点代表拥有的面积
一开始以为最长的一条边不用走，但这样好像变得非常难
*/
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
n edge
len: (t-n*m)/n=t/n-m
h: (len/2)/tan(pi/n)
  =(t/n-m)/2/tan(pi/n)
S: n*len*h/2
  =n*((t/n-m)^2) / (4tan(pi/n))
fuck math, deduction in md
so... maybe ternary search ?
*/
using LD=long double;
const LD pi=acosl(-1);
void solve(){
	int m,t;
	cin>>m>>t;
	LD ans=LD(0.0);
	auto calc=[&](const int& n)->LD{
		LD x=LD(t)/n-m;
		LD res=x*x/4*n;
		res/=tanl(pi/n);
		ans=fmax(ans,res);
		return res;
	};
	int l=3,r=t/m;
	while(r-l>10){
		int lmid=(l*2+r)/3;
		int rmid=(l+r*2)/3;
		LD fl=calc(lmid);
		LD fr=calc(rmid);
		if(fl<fr) l=lmid;
		else if(fl>fr) r=rmid;
		else l=lmid,r=rmid;
	}
	for(int i=l;i<=r;++i) calc(i);
	cout<<ans<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	cout<<fixed<<setprecision(8);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
