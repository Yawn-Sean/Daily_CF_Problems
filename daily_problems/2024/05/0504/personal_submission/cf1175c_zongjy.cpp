void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	k++;
	if (k == 1) {
		std::cout << a[1] << '\n';
		return;
	}
	int ans = 0, mx = inf;
	for (int l = 1, r = k; r <= n; l++, r++) {
		int tmp = (a[r] - a[l] + 1) / 2;
		if (tmp < mx) {
			mx = tmp;
			ans = (a[r] + a[l]) / 2;
		}
	}
	std::cout << ans << '\n';
}