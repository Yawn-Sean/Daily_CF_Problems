void solve() {
	int n, C, D;
	std::cin >> n >> C >> D;
	std::vector<pii> coin, dmd;
	int mc = 0, md = 0;
	for (int i = 0; i < n; i++) {
		int b, p;
		std::cin >> b >> p;
		std::string s;
		std::cin >> s;
		if (s == "C") {
			if (p <= C) {
				coin.push_back({p, b});
				mc = std::max(mc, b);
			}
		} else {
			if (p <= D) {
				dmd.push_back({p, b});
				md = std::max(md, b);
			}
		}
	}
	// C + D
	int ans = 0;
	if (mc && md) {
		ans = mc + md;
	}

	// C + C
	if (coin.size() >= 2) {
		std::sort(coin.begin(), coin.end());
		int cn = coin.size();
		std::vector<int> ct_pre(cn);
		ct_pre[0] = coin[0].second;
		for (int i = 1; i < cn; i++) {
			int c1 = coin[i].first, b1 = coin[i].second;
			if (c1 + coin[0].first > C) {
				break;
			}
			int dis = std::distance(coin.begin(), std::lower_bound(coin.begin(), coin.begin() + i, std::make_pair(C - c1 + 1, -inf)));
			-- dis;

			int c2 = coin[dis].first, b2 = ct_pre[dis];
			ans = std::max(ans, b1 + b2);
			ct_pre[i] = std::max(ct_pre[i - 1], b1);
		}
	}

	if (dmd.size() >= 2) {
		std::sort(dmd.begin(), dmd.end());
		int dn = dmd.size();
		std::vector<int> dt_pre(dn);
		dt_pre[0] = dmd[0].second;
		for (int i = 1; i < dmd.size(); i++) {
			int d1 = dmd[i].first, b1 = dmd[i].second;
			if (d1 + dmd[0].first > D) {
				break;
			}
			int dis = std::distance(dmd.begin(), std::lower_bound(dmd.begin(), dmd.begin() + i, std::make_pair(D - d1 + 1, -inf)));
			-- dis;

			int d2 = dmd[dis].first, b2 = dt_pre[dis];
			ans = std::max(ans, b1 + b2);
			dt_pre[i] = std::max(dt_pre[i - 1], b1);
		}
	}
	std::cout << ans << '\n';
}