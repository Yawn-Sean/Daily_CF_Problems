void solve() {
	i64 n, k, x;
	std::cin >> n >> k >> x;
	std::vector<i64> a(n), b(n);
	std::multiset<std::pair<i64, int>> ms;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] < 0) {
			cnt ++;
		}
		ms.insert({std::llabs(a[i]), i});
	}

	int rev_id = -1;
	if (cnt % 2 == 0) {
		auto [cur, id] = *ms.begin(); ms.erase(ms.begin());
		if (cur >= x * k) {
			cur -= x * k;
			k = 0;
		} else {
			rev_id = id;
			k -= cur / x + 1;
			cur = x - cur % x;
		}
		ms.insert({cur, id});
	}
	while (k) {
		auto [cur, id] = *ms.begin(); ms.erase(ms.begin());
		cur += x;
		k --;
		ms.insert({cur, id});
	}
	while (ms.size()) {
		auto [cur, id] = *ms.begin(); ms.erase(ms.begin());
		b[id] = cur;
		if (a[id] < 0) {
			b[id] *= -1LL;
		}
		if (id == rev_id) {
			b[id] *= -1LL;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << b[i] << " \n"[i == n - 1];
	}
}