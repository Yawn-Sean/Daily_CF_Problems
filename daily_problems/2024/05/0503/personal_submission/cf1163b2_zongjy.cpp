void solve() {
	int n;
	std::cin >> n;
	map<int, int> f, g;
	int mx = -1, ans = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		f[x]++;
		mx = max(mx, f[x]);
		if (f[x] > 1) {
			g[f[x] - 1]--;
		}
		g[f[x]]++;
		if (f.size() == 1) {
			ans = max(ans, i);
		}
		if (mx == 1 && g[mx] == f.size()) {
			ans = max(ans, i);
		}
		if (mx > 1 && g[mx] == 1 && g[mx - 1] == f.size() - 1) {
			ans = max(ans, i);
		}
		if (g[mx] == f.size() - 1 && g[1] == 1) {
			ans = max(ans, i);
		}
	}
	std::cout << ans << '\n';
}