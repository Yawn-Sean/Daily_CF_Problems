void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> nums(n), ans(n);
	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	std::vector<int> stk, typ;
	for (int i = 0; i < m; i++) {
		int op, rg;
		std::cin >> op >> rg;
		while (stk.size() && stk.back() <= rg) {
			stk.pop_back();
			typ.pop_back();
		}
		if (stk.size() && typ.back() == op) continue;
		stk.push_back(rg);
		typ.push_back(op);
	}

	for (int i = stk[0]; i < n; i++) {
		ans[i] = nums[i];
	}
	sort(nums.begin(), nums.begin() + stk[0], less<int>());

	int q = stk.size(), l = 0, r = stk[0] - 1;
	stk.push_back(0);
	for (int i = 0; i < q; i++) {
		for (int j = stk[i] - 1; j >= stk[i + 1]; j--) {
			if (typ[i] == 1) {
				ans[j] = nums[r--];
			} else {
				ans[j] = nums[l++];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << (i == n - 1 ? '\n' : ' ');
	}
}