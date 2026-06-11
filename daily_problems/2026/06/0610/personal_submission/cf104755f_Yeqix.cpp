#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<i64> b(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	map<i64, i64> mp;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			i64 y = a[j] * 2 - b[i];
			mp[y]++;
		}
	}

	set<int> st;
	for (const auto& [l, r] : mp) {
		if (r == n) {
			st.insert(l);
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			i64 y = a[j] * 2 - b[i];
			if (st.count(y)) {
				x = 1;
				break;
			}
		}
		if (!x) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
	cout << st.size() << "\n";
	for (const auto& v : st) {
		cout << v << " ";
	}
	return 0;
}