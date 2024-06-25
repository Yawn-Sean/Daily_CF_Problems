#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;

int N = 502;

int main() {
	int n,m;cin >> n >> m;
	string b;cin >> b;
	string s;cin >> s;

	vector<int> ne(m+1);

	vector<array<int,2>> trans(m+1);

	vector<vector<int>> dp(m + 1, vector<int>(n - m + 4, 1e9));
	dp[0][0] = 0;
	int j = 0;
	for (int i = 2;i <= m;++i) {
		while (j && s[j] != s[i - 1]) j = ne[j];
		if (s[j] == s[i - 1]) {
			j++;
		}
		ne[i] = j;
	}
	
	for (int i = 0;i <= m;++i) {
		int j = i;
		if (j == n) {
			j = ne[j];
		}
		while (j && s[j] != '1') j = ne[j];
		if (s[j] == '1') {
			j++;
		}
		trans[i][1] = j;
		j = i;
		if (j == m) {
			j = ne[j];
		}
		while (j && s[j] != '0') j = ne[j];
		if (s[j] == '0') {
			j++;
		}
		trans[i][0] = j;
	}

	for (int i = 0;i < n;++i) {
		vector<vector<int>> ndp(m + 1, vector<int>(n-m+4, 1e9));
		for (int j = 0;j <= n-m+2;++j) {
			for (int lst = 0;lst <= m;++lst) {
				int zp = trans[lst][0];
				ndp[zp][j + (zp == m)] = min(ndp[zp][j + (zp == m)], dp[lst][j] + (b[i] == '0' ? 0 : 1));
				zp = trans[lst][1];
				ndp[zp][j + (zp == m)] = min(ndp[zp][j + (zp == m)], dp[lst][j] + (b[i] == '1' ? 0 : 1));
			}
		}
		swap(dp, ndp);
	}

	for (int k = 0;k < n - m + 2;++k) {
		int r = 1e9;
		for (int z = 0;z <= m;++z) {
			r = min(r, dp[z][k]);
		}
		if (r < 1e9) {
			cout << r << " \n"[k == n - m + 1];
		}
		else {
			cout << -1 << " \n"[k==n-m+1];
		}
	}

	return 0;
}