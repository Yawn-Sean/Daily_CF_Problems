#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> pwDist(1'000'000, 2'000'000);
	long long pw = pwDist(rng);

	auto gen = [&]() -> long long {
		while (true) {
			long long x = static_cast<long long>(rng() & ((1ULL << 40) - 1));
			if (gcd(x, pw) == 1) return x;
		}
	};

	long long rnd1 = gen();
	long long rnd2 = gen();

	vector<long long> pw1(k + 1, 1), pw2(k + 1, 1);
	for (int i = 0; i < k; i ++) {
		pw1[i + 1] = pw1[i] * pw % rnd1;
		pw2[i + 1] = pw2[i] * pw % rnd2;
	}

	vector<int> p(k);
	iota(p.begin(), p.end(), 0);

	long long v1 = 0, v2 = 0;
	for (int i = 0; i < k; i ++) {
		v1 = (v1 + pw1[i] * p[i]) % rnd1;
		v2 = (v2 + pw2[i] * p[i]) % rnd2;
	}

	map<pair<long long, long long>, int> cnt;
	cnt[{v1, v2}] = 1;

	long long ans = 0;

	while (n --) {
		int x, y;
		cin >> x >> y;
		x --, y --;

		v1 = (v1 + (p[y] - p[x]) * (pw1[x] - pw1[y])) % rnd1;
		v2 = (v2 + (p[y] - p[x]) * (pw2[x] - pw2[y])) % rnd2;
		if (v1 < 0) v1 += rnd1;
		if (v2 < 0) v2 += rnd2;

		swap(p[x], p[y]);

		pair<long long, long long> key = {v1, v2};
		ans += cnt[key];
		cnt[key] ++;
	}

	cout << ans << '\n';
	
	return 0;
}
