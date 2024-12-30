void solve() {
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> cnt(n, 0), lst(n, n - 1), ans(n, 0);
	for (int i = 0; i < m; i++) {
		i64 b, e;
		std::cin >> b >> e;
		b--, e--;
		cnt[b] ++;
		lst[b] = std::min(lst[b], (e - b + n) % n);
	}
	i64 mx = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i]) {
			mx = std::max(mx, (cnt[i] - 1) * n + lst[i] + i);
		}
	}
	for (int i = 0; i < n; i++) {
		ans[i] = mx - i;
		if (cnt[i]) {
			mx = std::max(mx, cnt[i] * n + i + lst[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1 ? 1 : 0];
	}
}