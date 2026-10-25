#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
using LL=long long;

//
const int T=1e4+1;
const int MOD=1e9+7;
void solve() {
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<LL>dp(2*T+10);
	LL ans=0;
	for(int i=1;i<=n;++i){
		vector<LL>ndp(2*T+10);
		dp[T]=(dp[T]+1)%MOD;
		for(int j=-T;j<=T;++j){
			int L=j-a[i],R=j+a[i];
			if(T+L>=0){
				ndp[j+T]=(ndp[j+T]+dp[T+L])%MOD;
			}
			if(T+R<sz(ndp)){
				ndp[j+T]=(ndp[j+T]+dp[T+R])%MOD;
			}
		}
		dp=ndp;
		ans=(ans+dp[T])%MOD;
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
