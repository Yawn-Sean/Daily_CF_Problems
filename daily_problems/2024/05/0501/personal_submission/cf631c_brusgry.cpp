void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	std::vector<std::array<int, 2> > op;
	for (int i = 1; i <= m; i ++) {
		int o, r;
		std::cin >> o >> r;
		while (op.size() && r >= op.back()[1]) {
			op.pop_back();
		}
		op.push_back({o, r});
	}
	op.push_back({0, 0});
	std::vector<int> ans(n + 1);
	int R = op[0][1];
	for (int i = R + 1; i <= n; i ++) {
		ans[i] = a[i];
	}
	std::sort(a.begin() + 1, a.begin() + R + 1);
	int l = 1, r = R;
	int siz = op.size();
	for (int i = 1; i < siz; i ++) {
		int len = op[i - 1][1] - op[i][1];
		if (op[i - 1][0] & 1) {
			// max - min
			for (int j = op[i - 1][1]; j > op[i][1]; j --) {
				ans[j] = a[r --];
			}
		} else {
			for (int j = op[i - 1][1]; j > op[i][1]; j --) {
				ans[j] = a[l ++];
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << '\n';
}
