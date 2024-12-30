#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	map<char, vector<int>> d;
	d['L'] = {-1};
	d['D'] = {0};
	d['W'] = {1};
	d['?'] = {-1, 0, 1};
	
	
	vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -114514));
	dp[0][k] = 0;
	
	for (int i = 0; i < n; i++) {
		for (auto& dj: d[s[i]]) {
			for (int j = 1; j < 2 * k; j++) {
				if (dp[i][j] != -114514) {
					dp[i + 1][j + dj] = dj;
				}
			}		
		}
	}
	
	int fin;
	if (dp[n][0] != -114514) {
		fin = 0;
	} else if (dp[n][2 * k] != -114514) {
		fin = 2 * k;
	} else {
		cout << "NO\n";
		return 0;
	}
	
	map<int, char> status;
	status[-1] = 'L';
	status[0] = 'D';
	status[1] = 'W';
	
	vector<char> ans;
	int cur = fin;
	for (int i = n; i > 0; i--) {
		ans.push_back(status[dp[i][cur]]);
		cur -= dp[i][cur];
	}
	reverse(ans.begin(), ans.end());
	for (auto& ch: ans) {
		cout << ch;
	}
	return 0;
}
