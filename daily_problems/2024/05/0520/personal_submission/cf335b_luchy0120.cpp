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

const int N = 2600;
int dp[N][N];
array<int, 2> b[N][N];

int dfs(int l, int r, string& s) {
	if (r < l) {
		return 0;
	}
	if (dp[l][r] != 0) {
		return dp[l][r];
	}

	if (l == r) {
		b[l][r] = { 0,-1 };
		return dp[l][l] = 1;
	}

	if (s[l] == s[r]) {
		int v = dfs(l + 1, r - 1, s);
		b[l][r] = { 1, -1 };
		return dp[l][r] = 2 + v;
	}
	int v1 = dfs(l + 1, r, s);
	int v2 = dfs(l, r - 1, s);

	if (v1 > v2) {
		b[l][r] = { 1, 0 };
		return dp[l][r] = v1;
	}
	b[l][r] = { 0, -1 };
	return dp[l][r] = v2;
}

int main() {
	string s;cin >> s;
	int n = s.size();

	if (n >= 2600) {
		vector<int> d(26);
		for (char c : s) {
			d[c - 'a']++;
		}
		for (int i = 0;i < 26;++i) {
			if (d[i] >= 100) {
				cout << string(100, (char)(i + 'a'));
				return 0;
			}
		}
	}


	int v = dfs(0, n - 1, s);

	if (v >= 100) {
		int l = 0;
		int r = n - 1;

		string ans = "";

		while (1) {
			int nl = b[l][r][0] + l;
			int nr = b[l][r][1] + r;
			if (nl > l && nr < r) {
				ans.push_back(s[l]);
				if (ans.size() == 50) {
					cout << ans;
					reverse(ans.begin(), ans.end());
					cout << ans;
					return 0;
				}
			}

			l = nl;
			r = nr;

		}
	}
	else {
		int l = 0;
		int r = n - 1;

		string ans = "";

		while (l < r) {
			int nl = b[l][r][0] + l;
			int nr = b[l][r][1] + r;
			if (nl > l && nr < r) {
				ans.push_back(s[l]);
			}

			l = nl;
			r = nr;

		}
		cout << ans;
		if (v % 2 == 1) {
			cout << s[l];
		}
		reverse(ans.begin(), ans.end());
		cout << ans;
	}



	return 0;
}