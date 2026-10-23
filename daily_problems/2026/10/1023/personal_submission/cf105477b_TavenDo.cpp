#include <bits/stdc++.h>
using namespace std;
using LL=long long;

//预处理然后O(1)查表

const int mxn=205;
const int MOD=1e9+7;
vector<vector<LL>>mem(mxn+1,vector<LL>(mxn+1));  //mem[a][b]  有a对括号,最高高度为b的方案数

void init(){
	vector<vector<LL>>dp(mxn+1,vector<LL>(mxn+1));    //dp[a][b] 目前数值a的最大值为b的方案数
	dp[0][0]=1;
	for(int i=1;i<=2*mxn;++i){
		vector<vector<LL>>ndp(mxn+1,vector<LL>(mxn+1));
		for(int a=0;a<=mxn;++a){
			int na=a+1;
			if(na<mxn){
				for(int b=0;b<mxn;++b){
					ndp[na][max(na,b)]=(ndp[na][max(na,b)]+dp[a][b])%MOD;
				}
			}
			na=a-1;
			if(na>=0){
				for(int b=0;b<=mxn;++b){
					ndp[na][b]=(ndp[na][b]+dp[a][b])%MOD;
				}
			}
		}
		dp.swap(ndp);
		if(!(i&1)){
			for(int j=0;j<=mxn;++j){
				mem[i/2][j]=dp[0][j];
			}
		}
	}
}

void solve() {
	int n,k;
	cin>>n>>k;
	if(k>n){
		cout<<0<<endl;
		return;
	}
	cout<<mem[n][k]<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	init();
	while (loop--){
		solve();
	}
	return 0;
}