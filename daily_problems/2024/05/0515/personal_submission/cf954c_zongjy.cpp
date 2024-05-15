void solve() {
	int n;
	std::cin >> n;
	std::vector<int> pos(n);
	int Y = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> pos[i];
	}
	for (int i = 1; i < n; i++) {
		int del = std::abs(pos[i] - pos[i - 1]);
		if (del == 0) {
			std::cout << "NO\n";
			return;
		} else if (del > 1) {
			if (Y && Y != del) {
				std::cout << "NO\n";
				return;
			} else if (!Y) {
				Y = del;
			}
		}
	}
	if (Y == 0) {
		std::cout << "YES\n1 1000000000\n";
		return;
	}

	int x1 = (pos[0] + Y - 1) / Y, y1 = pos[0] - (x1 - 1) * Y;
	int X = x1;
	for (int i = 1; i < n; i++) {
		int x2 = (pos[i] + Y - 1) / Y, y2 = pos[i] - (x2 - 1) * Y;
		X = std::max(X, x2);
		int del = pos[i] - pos[i - 1];
		if ((del == 1 && y1 == Y) || (del == -1 && y1 == 1)) {
			std::cout << "NO\n";
			return;
		}
		x1 = x2, y1 = y2;
	}
	std::cout << "YES\n" << X << ' ' << Y << '\n';
}