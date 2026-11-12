#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//
void solve() {
	int n;
	cin>>n;
	int ans=1;
	vector<int>dp(62,0);
	vector<set<LL>>adj(62);
	LL x;
	for(int i=1;i<=n;++i){
		cin>>x;
		if(x==0){
			continue;
		}
		int cnt=0;
		LL y=x;
		while(y){
			y>>=1;
			++cnt;
		}
		--cnt;
		adj[cnt].insert(x);
	}
	for(int i=0;i<=61;++i){
		vector<int>ndp=dp;
		for(auto &u:adj[i]){
			int mxn=0;
			LL cur=u,cnt=0;
			vector<int>X;
			while(cur){
				if(cur&1){
					mxn=max(mxn,dp[cnt]);
				}
				cur>>=1;
				++cnt;
			}
			++mxn;
			ans=max(mxn,ans);
			ndp[i]=max(ndp[i],mxn);
		}
		ndp.swap(dp);
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}