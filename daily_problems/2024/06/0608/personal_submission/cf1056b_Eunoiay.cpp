int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto Ceil = [&](int a, int b) {
		if (a < 0) {
			return a / b;
		}
		return (a + b - 1) / b;
	};

	auto Floor = [&](int a, int b) {
		if (a < 0) {
			return (a - b + 1) / b;
		}
		return a / b;
	};

	auto get = [&](int x) {
		return Floor(n - x, m) - Ceil(1 - x, m) + 1;
	};

	auto std_get = [&](int x) {
		return (n + m - x) / m;
	};

	i64 ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i * i + j * j) % m == 0) {
				ans += 1LL * get(i) * get(j);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
