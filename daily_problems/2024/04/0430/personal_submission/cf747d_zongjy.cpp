void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> dist;
	int t;
	int last = -100, winter = 0, spj = -1;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		if (t < 0) {
			if (last >= 0 && i - last > 1) {
				dist.push_back(i - last - 1);
			}
			last = i;
			winter++;
		} else {
			if (i == n - 1) spj = i - last;
		}
	}
	if (winter > k) {
		std::cout << "-1\n";
		return;
	}
	int seg = dist.size();
	if (seg == 0 && last < 0) {
		std::cout << "0\n";
		return;
	}

	int ans1 = seg * 2 + 1, ans2 = seg * 2 + 1;
	int use1 = winter, use2 = winter;
	sort(dist.begin(), dist.end());

	// choose -1
	if (spj != -1) {
		ans1 ++;
		ans2 ++;
		if (use2 + spj <= k) {
			ans2 --;
			use2 += spj;
		}
	}
	int id1 = 0, id2 = 0;
	while (id1 < seg && use1 + dist[id1] <= k) {
		use1 += dist[id1++];
		ans1 -= 2;
	}
	while (id2 < seg && use2 + dist[id2] <= k) {
		use2 += dist[id2++];
		ans2 -= 2;
	}
	if (spj == -1) {
		std::cout << ans1 << '\n';
		return;
	} else {
		std::cout << min(ans1, ans2) << '\n';
		return;
	}
}