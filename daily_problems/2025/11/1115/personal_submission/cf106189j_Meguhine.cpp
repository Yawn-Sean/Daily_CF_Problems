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
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector dp(n+1,vector<int>(n+1));
	vector pre(n+1,vector<int>(n+1,-1));
	for(int len=2;len<=n;++len){
		for(int i=1,j=len;j<=n;++i,++j){
			if(a[i]%a[j]==0 || a[j]%a[i]==0){
				dp[i][j]=dp[i+1][j-1]+2;
				pre[i][j]=0;
			}
			for(int k=i;k<j;++k){
				if(updmx(dp[i][j],dp[i][k]+dp[k+1][j])){
					pre[i][j]=k;
				}
			}
		}
	}
	vector<int>b;
	auto dfs=[&](auto&& self,int l,int r)->void{
		if(pre[l][r]==-1){
			for(int i=l;i<=r;++i){
				b.emplace_back(i);
			}
			return;
		}
		if(!pre[l][r]){
			self(self,l+1,r-1);
			return;
		}
		self(self,l,pre[l][r]);
		self(self,pre[l][r]+1,r);
	};
	dfs(dfs,1,n);
	cout<<b.size()<<'\n';
	for(auto& x:b) cout<<x<<' ';
	return 0;
}
