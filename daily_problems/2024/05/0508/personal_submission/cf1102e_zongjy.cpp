void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), lst(n + 1);
	std::map<int, int> pos;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		if (!pos.count(a[i])) {
			pos[a[i]] = i;
		}
		lst[i] = pos[a[i]];
	}
	i64 ans = 1;
	int cur = 1;
	for (int i = 1; i <= n - 1; i++) {
		cur = std::max(cur, lst[i]);
		if (cur == i) {
			ans = (ans * 2) % mod;
		}
	}
	std::cout << ans << '\n';
}