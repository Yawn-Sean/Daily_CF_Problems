void solve() {
	int n;
	std::cin >> n;
	std::vector<int> tow(n + 1), ans(n + 1, inf);
	for (int i = 1; i <= n; i++) {
		std::cin >> tow[i];
	}
	ans[1] = ans[n] = 1;
	for (int i = 1; i < n - 1; i++) {
		ans[i + 1] = min(tow[i + 1], ans[i] + 1);
	}

	int res = 1;
	for (int i = n; i > 2; i--) {
		ans[i - 1] = min(ans[i - 1], ans[i] + 1);
		res = max(res, ans[i - 1]);
	}
	std::cout << res << '\n';
}