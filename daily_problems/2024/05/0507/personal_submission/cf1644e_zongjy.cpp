void solve() {
	i64 n;
	std::cin >> n;
	std::string op;
	std::cin >> op;
	int len = op.length();
	i64 x = 1, y = 1;
	for (int i = 0; i < len; i++) {
		if (op[i] == 'R') {
			y ++;
		} else {
			x ++;
		}
	}
	if (x == 1 || y == 1) {
		std::cout << n << '\n';
		return;
	}

	i64 cx = 1, cy = 1, ans = 0;
	for (int i = 0; i < len; i++) {
		if (op[i] == 'R') {
			cy ++;
			ans += (cx == 1 ? n - 1 : x - cx);
		} else {
			cx ++;
			ans += (cy == 1 ? n - 1 : y - cy);
		}
	}
	std::cout << n * n - ans << '\n';
}