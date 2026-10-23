#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
using LL=long long;
using PLL=pair<LL,LL>;

//由于异或不产生进位，故拆分不同数位，分别计算贡献
const int MOD=1e9+7;
int pc(int x){
	int cnt=0;
	while(x){
		if(x&1)++cnt;
		x>>=1;
	}
	return cnt;
}
void solve() {
	int n;
	cin>>n;
	int m=30;
	vector<int>a(n),b(n);
	vector<vector<vector<bool>>>mp(n,vector<vector<bool>>(n,vector<bool>(m,false)));
	vector<vector<bool>>pref(n,vector<bool>(m));
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		cin>>b[i];
	}
	for(int k=0;k<m;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				mp[i][j][k]=((a[i]+b[j])>>k)&1;
			}
		}
	}
	int N=1<<n;
	LL ans=0;
	for(int k=0;k<m;++k){
		vector<vector<LL>>dp(N,vector<LL>(2));  //fi->0 se->1
		dp[0][0]=1<<k;
		for(int msk=0;msk<N;++msk){
			for(int i=0;i<n;++i){
				if((msk>>i)&1){
					continue;
				}
				int nxt=msk|(1<<i);
				int x=pc(msk);
				for(int t:{0,1}){
					dp[nxt][t]=(dp[nxt][t]+dp[msk][t^mp[x][i][k]])%MOD;
				}
			}
		}
		ans=(ans+dp[N-1][1])%MOD;
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}