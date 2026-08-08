#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 n, x, y, z;
	cin >> n >> x >> y >> z;
	string s;
	cin >> s;

	priority_queue<array<i64, 2>> que;
	vector<i64> nxt(n);
	for (int i = 1, j = 0; i < n; i++) {
		while ( j && s[i] != s[j]) {
			j = nxt[j - 1];
		}
		j += (s[i] == s[j]);
		nxt[i] = j;
		if (nxt[i]) {
			que.push({(j - 1) * x - z * (i + 1), i});
		}
	}

	nxt.assign(n, 0);
	i64 ans = -inf;
	for (int i = n - 2, j = n - 1; i >= 0; i--) {
		while (j < n - 1 && s[i] != s[j]) {
			j = n - 1 - nxt[j + 1];
		}
		j -= (s[i] == s[j]);
		nxt[i] = n - 1 - j;

		while (!que.empty() && que.top()[1] >= i) {
			que.pop();
		}
		if (!que.empty() && nxt[i]) {
			ans = max(ans, que.top()[0] + (nxt[i] - 1) * y + z * (i + 1) + x + y - z);
		}
	}

	if (ans == -inf) {
		cout << "0";
	} else {
		cout << ans;
	}
	return 0;
}