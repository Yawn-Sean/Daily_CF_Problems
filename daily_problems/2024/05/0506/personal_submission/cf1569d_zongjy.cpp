void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> xs(k), ys(k);
	std::vector<int> vert(n), cntx(n), hori(m), cnty(m);
	std::map<int, std::map<int, int>> mpx, mpy;
	for (int i = 0; i < n; i++) {
		std::cin >> vert[i];
	}
	sort(vert.begin(), vert.end());
	for (int i = 0; i < m; i++) {
		std::cin >> hori[i];
	}
	sort(hori.begin(), hori.end());
	for (int i = 0; i < k; i++) {
		std::cin >> xs[i] >> ys[i];
	}

	for (int i = 0; i < k; i++) {
		auto it = std::lower_bound(vert.begin(), vert.end(), xs[i]);
		auto jt = std::lower_bound(hori.begin(), hori.end(), ys[i]);
		int dx = std::distance(vert.begin(), it);
		int dy = std::distance(hori.begin(), jt);

		if (*it == xs[i] && *jt == ys[i]) {
			continue;
		} else if (*jt == ys[i]) {
			mpy[dy][dx] ++;
			cntx[dx] ++;
		} else if (*it == xs[i]) {
			mpx[dx][dy] ++;
			cnty[dy] ++;
		}
	}
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1LL * cntx[i] * (cntx[i] - 1) / 2;
		for (auto [k, v] : mpx[i]) {
			ans -= 1LL * v * (v - 1) / 2;
		}
	}
	for (int i = 0; i < m; i++) {
		ans += 1LL * cnty[i] * (cnty[i] - 1) / 2;
		for (auto [k, v] : mpy[i]) {
			ans -= 1LL * v * (v - 1) / 2;
		}
	}
	std::cout << ans << "\n";
}