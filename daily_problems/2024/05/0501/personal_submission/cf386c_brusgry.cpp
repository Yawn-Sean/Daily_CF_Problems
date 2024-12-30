void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	s = " " + s;
	std::set<char> st;
	for (int i = 1; i <= n; i ++) {
		st.insert(s[i]);
	}
	int siz = st.size();
	std::cout << siz << '\n';
	auto work = [&](int x) -> int {
		std::vector<int> cnt(26);
		int l = 1, num = 0, res = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt[s[i] - 'a'] == 0) {
				num ++;
			}
			cnt[s[i] - 'a'] ++;

			while (num > x) {
				if (cnt[s[l] - 'a'] == 1) {
					num --;
				}
				cnt[s[l] - 'a'] --;
				l ++;
			}
			if (num <= x) {
				res += i - l + 1;
			}
		}
		return res;
	};
	std::vector<int> g(siz + 1), dp(siz + 1);
	for (int i = 1; i <= siz; i ++) {
		g[i] = work(i);
	}
	for (int i = 1; i <= siz; i ++) {
		dp[i] = g[i] - g[i - 1];
	} 
	for (int i = 1; i <= siz; i ++) {
		std::cout << dp[i] << '\n';
	}
}
