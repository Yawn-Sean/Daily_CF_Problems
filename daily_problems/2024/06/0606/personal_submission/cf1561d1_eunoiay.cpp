int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> f(n + 1);
	f[1] = 1;

	int sum = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (f[i] + sum) % m;
		for (int l = 2, r; l <= i; l = r + 1) {
			r = i / (i / l);
			f[i] += 1LL * (r - l + 1) * f[i / l] % m;
			f[i] %= m;
		}
		sum = (sum + f[i]) % m;
	}
		
	cout << f[n] << "\n";

	return 0;
}
