using i64 = long long;

struct my_hash {
  	static uint64_t splitmix64(uint64_t x) {
	    x += 0x9e3779b97f4a7c15;
	    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	    return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
    	static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    	return splitmix64(x + FIXED_RANDOM);
  	}

	// 针对 std::pair<int, int> 作为主键类型的哈希函数
	size_t operator()(std::pair<uint64_t, uint64_t> x) const {
	    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
	    return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};

constexpr i64 base[11] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000
};


void solve() {
	i64 n, k;
	std::cin >> n >> k;
	std::vector<i64> mo(n), ws(n);
	std::unordered_map<i64, i64, my_hash> mp[11];
	for (int i = 0; i < n; i++) {
		int x, w = 0;
		std::cin >> x;
		mo[i] = x % k;
		while (x) {
			w ++;
			x /= 10;
		}
		ws[i] = w;
	}
	
	// 贴在长度j 前面时余数对应个数
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 10; j++) {
			mp[j][(mo[i] % k) * (base[j] % k) % k] ++;
		}
	}

	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		i64 need = (k - mo[i]) % k;
		ans += mp[ws[i]][need];
		if (mo[i] * (1 + base[ws[i]]) % k == 0) {
			-- ans;
		}
	}
	std::cout << ans << '\n';
}