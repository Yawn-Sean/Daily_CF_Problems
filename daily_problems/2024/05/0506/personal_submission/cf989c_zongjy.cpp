void solve() {
	std::string ans[50];
	std::vector<int> val(4), pos(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> val[i];
		pos[i] = i;
	}
	std::sort(pos.begin(), pos.end(), 
		[&](int i, int j) {
			return val[i] > val[j];
		});

	for (auto& s : ans) {
		s = std::string(50, char('A' + pos[3]));
	}

	std::function<int(int)> get = [&](int pre) -> int {
		int id = 0;
		for (; id < 3; id++) {
			if (id == pre) continue;
			if (id == 0 && val[pos[id]] > 1) {
				break;
			} else if ((id == 1 || id == 2) && val[pos[id]] > 0) {
				break;
			}
		}
		return id;
	};

	int x = 0, y = 0, u = -1;

	while (1) {
		int v = get(u);
		if (get(-1) == 3) {
			for (; y < 49; y++) {
				ans[x][y] = char('A' + pos[v]);
			}
			y = 0;
			x += 2;
			break;
		} else {
			ans[x][y] = char('A' + pos[v]);
			if (v != 3) val[pos[v]] --;
			if (y == 48) {
				y = 0;
				u = -1;
				x += 2;
			} else {
				y ++;
				u = v;
			}
		}
	}
	// isolation
	ans[x ++] = std::string(50, char('A' + pos[0]));
	val[pos[3]] --;
	assert(y == 0);
	while (val[pos[3]]) {
		ans[x][y ++] = char('A' + pos[3]);
		ans[x][y ++] = char('A' + pos[0]);
		val[pos[3]] --;
		if (y == 50) {
			ans[x + 1] = std::string(50, char('A' + pos[0]));
			x += 2;
			y = 0;
		}
	}
	for (; y < 50; y++) {
		ans[x][y] = char('A' + pos[0]);
	}

	std::cout << x + 1 << " 50\n";
	for (int i = 0; i <= x; i++) {
		std::cout << ans[i] << '\n';
	}
}