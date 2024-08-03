void ask(const vector<int>& a) {
	std::string que = "?";
	for (int x : a) {
		que += " " + to_string(x);
	}
	std::cout << que << '\n';
	std::cout.flush();
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> query(k);
	for (int i = 0; i < k; i++) {
		query[i] = i + 1;
	}
	ask(query);
	int pos, num;
	std::cin >> pos >> num;

	int p1 = pos, val1 = num, cnt1 = 1;
	int val2, cnt2 = 0;

	for (int i = 0; i < k; i++) {
		query[i] = k + 1;
		ask(query);
		query[i] = i + 1;
		std::cin >> pos >> num;
		if (pos == p1) {
			cnt1++;
		} else {
			cnt2++;
		}
		if (i + 1 == p1) {
			val2 = num;
		}
	}
	if (val1 < val2) std::cout << "! " << cnt2 << '\n';
	else std::cout << "! " << cnt1 << '\n';
}