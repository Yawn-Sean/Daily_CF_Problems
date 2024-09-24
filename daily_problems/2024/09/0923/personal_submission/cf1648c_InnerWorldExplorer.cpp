constexpr int MOD = 998244353;
constexpr int N = 200010;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> s(n), t(m);
	vector<int> cnt(N);
	Fenwick<int> fenwick(N);
	for (auto &x : s) {
		cin >> x;
		fenwick.add(x, 1);
		cnt[x] ++;
	}
	for (auto &x : t) {
		cin >> x;
	}
	vector<int> fac(N + 1, 1), g(N + 1, 1);
	for (int i = 2; i <= N; i ++) {
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	}

	g[N] = binpow(fac[N], MOD - 2, MOD);

	for (int i = N; i >= 1; i --)
		g[i - 1] = 1LL * g[i] * i % MOD;

	int cur = 1;
	for (auto &v : cnt) {
		cur = 1LL * cur * g[v] % MOD;
	}

	long long ans = 0;
	for (int i = 0; i < min(n, m); i ++) {
		if (i < n - 1) {
			ans += 1LL * cur * fac[n - i - 1] % MOD * fenwick.sum(t[i]) % MOD;
		} else {
			ans += n < m && fenwick.rangeSum(0, t[i] + 1) > 0;
		}
		if (cnt[t[i]] == 0) {
			break;
		}
		cur = 1LL * cur * cnt[t[i]] % MOD;
		fenwick.add(t[i], -1);
		cnt[t[i]] --;
	}
	cout << ans % MOD << endl;
	return 0;
}
