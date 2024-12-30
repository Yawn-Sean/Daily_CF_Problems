void solve() {
	int n;
	std::cin >> n;
	std::unordered_map<int, int> mp;
	int c;
	for (int i = 0; i < n; i++) {
		std::cin >> c;
		mp[c] ++;
	}
	std::map<int, int> cnt;
	for (auto [k, v] : mp) {
		cnt[v] ++;
	}

	if (cnt.size() == 1) {
		std::cout << cnt.begin()->second << '\n';
		return;
	} else {
		int m = cnt.begin()->first + 1, sz = cnt.size();
		for (; m >= 1; m--) {
			int ans = 0;
			bool ok = true;
			for (auto [k, v] : cnt) {
				if (k % m != 0 && (k / m + k % m < m - 1)) {
					ok = false;
					break;
				} else {
					ans += (k / m + (k % m == 0 ? 0 : 1)) * v;
				}
			}
			if (ok) {
				cout << ans << '\n';
				return; 
			}
		}
	}
}