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
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

constexpr int p=5; // price per gold (cents)
constexpr int minw=100; // min weight per cube
void solve(){
	int V; cin>>V; V*=100; // (cents)
	const int need_gold=V/p+1;
	dbg(need_gold);
	ai3 w{}; cin>>w[0]>>w[1]>>w[2];
	ai3 m{}; cin>>m[0]>>m[1]>>m[2];
	vector dp(m[0]+1,vector<vector<int>>(m[1]+1,vector<int>(m[2]+1)));
	// dp[used_A][used_B][used_C] = max_profit (without considering at_least_one_make_money)
	/*
	consider m={1,2,3}, only 884 cases (>=minw)
	60*60*60*884, maybe ok
	*/
	vector<ai4>trans; trans.reserve(884);
	for(int k=0,gold_k=0,con_k=1;k<=m[2] && con_k;++k,gold_k+=w[2]){
		for(int j=0,gold_j=0,con_j=1;j<=m[1] && con_j;++j,gold_j+=w[1]){
			int i;
			if(gold_j+gold_k>=minw) i=0;
			else i=(minw-gold_j-gold_k-1)/w[0]+1;
			if(i>m[0]) continue;
			const int gold=gold_j+gold_k+i*w[0];
			trans.push_back(ai4{i,j,k,V-p*gold});
			con_j=(gold_j+gold_k<=minw);
		}
		con_k=(gold_k<=minw);
	}
	// sort(all(trans));
	for(int i=0;i<=m[0];++i){
		for(int j=0;j<=m[1];++j){
			for(int k=0;k<=m[2];++k){
				if(i) updmx(dp[i][j][k],dp[i-1][j][k]);
				if(j) updmx(dp[i][j][k],dp[i][j-1][k]);
				if(k) updmx(dp[i][j][k],dp[i][j][k-1]);
				for(const auto& [di,dj,dk,add]:trans){
					if(i>=di && j>=dj && k>=dk){
						updmx(dp[i][j][k],dp[i-di][j-dj][k-dk]+add);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m[0];++i){
		for(int j=0;j<=m[1];++j){
			const int gold_ij=i*w[0]+j*w[1];
			int k;
			if(gold_ij>=need_gold) k=0;
			else k=(need_gold-gold_ij-1)/w[2]+1;
			dbg(i,j,gold_ij,k);
			if(k>m[2]) continue;
			const int gold=gold_ij+k*w[2];
			int res=dp[m[0]-i][m[1]-j][m[2]-k];
			dbg("\t",i,j,k,res);
			res+=V-p*gold;
			updmx(ans,res);
		}
	}
	cout<<ans<<'\n';
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
