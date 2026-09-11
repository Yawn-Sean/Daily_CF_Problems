#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> td(n);
	vector<array<int,3>> ips(k);
	for(int i = 0; i < n; ++i) cin >> td[i].first >> td[i].second;
	for(int i = 0; i < k; ++i) cin >> ips[i][0] >> ips[i][1] >> ips[i][2];
	vector<int> dp(n + 1,1e9);
	vector<int> cvrtc(k,0); // 能覆盖到j的最早的ip下标
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		dp[i + 1] = dp[i] + td[i].second;
		for(int j = 0,p,d,c; j < k; ++j){
			p = ips[j][0],d = ips[j][1],c = ips[j][2];
			while(td[i].first - td[cvrtc[j]].first + 1 > p || i - cvrtc[j] + 1 > d) cvrtc[j]++;
			dp[i + 1] = min(dp[i + 1],dp[cvrtc[j]] + c);
		}
	}
	cout << dp[n] << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}