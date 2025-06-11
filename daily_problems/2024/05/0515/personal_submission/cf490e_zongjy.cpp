constexpr i64 shi[10] = {
	0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000
};

i64 calc(std::vector<i64>& pos, i64 init, i64 goal, bool from_1) {
	if (pos.empty()) {
		return init <= goal ? -1 : init;
	}
	int sz = pos.size();
	i64 l = from_1 ? shi[sz] : 0;
	i64 r = shi[sz + 1] - 1;
	i64 ans = -1;
	while (l <= r) {
		i64 mid = (l + r) / 2;
		i64 cur = init;
		for (int i = 1; i <= sz; i++) {
			cur += (mid % shi[i + 1]) / shi[i] * shi[pos[sz - i]];
		}
		if (cur > goal) {
			r = mid - 1;
			ans = cur;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		int le = s.length();
		
		std::vector<i64> pos;
		i64 base = 0;
		bool from1 = false;

		for (int j = 0; j < le; j++) {
			base *= 10;
			if (s[j] == '?') {
				if (j == 0) {
					from1 = true;
				}
				pos.push_back(le - j);
			} else {
				base += s[j] - '0';
			}
		}
		ans[i] = calc(pos, base, ans[i - 1], from1);
		if (ans[i] == -1) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << '\n';
	}
}