#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
	int n, K;
	cin >> n >> K;
	vector<vector<int>>dp(n + 2, vector<int>(K + 1));
	vector<string>ss = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<string>s(n + 1);
	for (int i = 1; i <= n; i++) cin >> s[i];
	//先处理-1
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; i--) {
		vector<int>t(10, -1);
		for (int j = 0; j <= 9; j++) {
			bool st = 0;
			int ans = 0;
			for (int k = 0; k <= 6; k++) {
				if (s[i][k] == '1' && ss[j][k] == '0') st = 1;
				if (st) break;
				if (s[i][k] == '0' && ss[j][k] == '1') ans++;
			}
			if (!st) t[ans] = max(t[ans], j);
		}
		// cout<<t[7]<<endl;

		for (int j = 0; j <= 9; j++) {
			if (t[j] == -1) continue;
			for (int k = j; k <= K; k++) {
				dp[i][k] |= dp[i + 1][k - j];
			}
		}
	}
	// cout<<dp[1][7]<<endl;

	if (!dp[1][K]) cout << -1 << endl;
	else {
		int tt = K;
		for (int i = 1; i <= n; i++) {
			vector<int>t(10, 10);
			for (int j = 0; j <= 9; j++) {
				bool st = 0;
				int ans = 0;
				for (int k = 0; k <= 6; k++) {
					if (s[i][k] == '1' && ss[j][k] == '0') st = 1;
					if (st) break;
					if (s[i][k] == '0' && ss[j][k] == '1') ans++;
				}
				if (!st) t[j] = ans;
			}
			// cout<<t[9]<<' '<<tt<<endl;
			for (int j = 9; j >= 0; j--) {
				if (t[j] == 10) continue;
				if (tt >= t[j] && dp[i + 1][tt - t[j]]) {
					tt -= t[j];
					cout << j;
					break;
				}
			}
		}
	}
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
