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
	vector<ai3>a(n);
	LL totr=0,totb=0;
	for(auto& [t,x,y]:a){
		char c;
		cin>>c>>x>>y;
		if(c=='R') t=0;
		else t=1;
		totr+=x;
		totb+=y;
	}
	const int m=1<<n;
	const int lim=n*(n-1)/2+1; // 1+2+...+(n-1)
	vector dp(m,vector<int>(lim,-1));
	dp[0][0]=0;
	for(int s=1;s<m;++s){
		int cr=0,cb=0; // cnt_r, cnt_b
		for(int i=0;i<n;++i) if(s>>i&1){
			if(!a[i][0]) ++cr;
			else ++cb;
		}
		for(int i=0;i<n;++i) if(s>>i&1){
			for(int dr=0;dr<lim;++dr){ // del_r
				const int& db=dp[s^(1<<i)][dr]; // del_b
				if(db==-1) continue;
				int pr=cr,pb=cb; // pre_cnt_r/b
				if(!a[i][0]) --pr;
				else --pb;
				int nr=dr+min(pr,a[i][1]);
				int nb=db+min(pb,a[i][2]);
				updmx(dp[s][nr],nb);
			}
		}
	}
	LL ans=max(totr,totb);
	for(int r=0;r<lim;++r){
		const int& b=dp[m-1][r];
		if(b==-1) continue;
		updmn(ans,max(totr-r,totb-b));
	}
	cout<<(ans+n); // additional n steps to gain cards
	return 0;
}
