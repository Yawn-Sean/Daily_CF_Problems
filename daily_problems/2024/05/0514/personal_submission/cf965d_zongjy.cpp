void solve() {
	int w, l;
	std::cin >> w >> l;
	std::vector<int> sto(w);
	for (int i = 1; i < w; i++) {
		std::cin >> sto[i];
	}
	int ans = inf, wnd = 0;
	for (int i = 1; i < w; i++) {
		if (i < l) {
			wnd += sto[i];
		} else {
			wnd += sto[i] - sto[i - l];
			ans = std::min(wnd, ans);
		}
	}
	std::cout << (ans == inf ? 0 : ans) << '\n';
}