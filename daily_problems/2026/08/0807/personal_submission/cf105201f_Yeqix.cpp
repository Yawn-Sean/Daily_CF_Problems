#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string t;
	cin >> t;

	int n = t.size();
	string s = "[-";
	for (int i = 0; i < n; i++) {
		s += t[i], s += "-";
	}
	s += "]";

	vector<int> fa(2 * n + 3, -1), r(2 * n + 3);
	int mid = 1, far = 1;
	for (int i = 1; i < s.size(); i++) {
		r[i] = min(r[(mid << 1) - i], far - i);
		while (s[i + r[i]] == s[i - r[i]]) {
			if (r[i]) {
				fa[i + r[i]] = i - r[i];
			}
			r[i]++;
		}
		if (far < i + r[i]) {
			mid = i, far = i + r[i];
		}
	}

	int ans = 0;
	for (int i = 2; i < s.size() - 1; i += 2) {
		ans += (fa[i] == -1);
	}
	cout << ans;
	return 0;
}