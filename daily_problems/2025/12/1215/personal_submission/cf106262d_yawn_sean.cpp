#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n), ys(n);

	for (auto &x: xs) cin >> x;
	for (auto &x: ys) cin >> x;

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	sort(order.begin(), order.end(), [&](int a, int b) {
		return 1ll * xs[b] * ys[a] < 1ll * xs[a] * ys[b];
	});

	vector<long long> down_xs = {0}, down_ys = {0};
	for (auto &x: order) {
		down_xs.push_back(down_xs.back() + xs[x]);
		down_ys.push_back(down_ys.back() + ys[x]);
	}

	reverse(order.begin(), order.end());
	vector<long long> up_xs = {0}, up_ys = {0};
	for (auto &x: order) {
		up_xs.push_back(up_xs.back() + xs[x]);
		up_ys.push_back(up_ys.back() + ys[x]);
	}

	long double ans = 0;
	int pt1 = 0, pt2 = 0;

	while (pt1 < n && pt2 < n) {
		long long l = max(up_xs[pt1], down_xs[pt2]);
		long long r = min(up_xs[pt1 + 1], down_xs[pt2 + 1]);

		if (l < r && l > 0) {
			long double kup = (long double)(up_ys[pt1 + 1] - up_ys[pt1]) / (up_xs[pt1 + 1] - up_xs[pt1]);
			long double kdown = (long double)(down_ys[pt2 + 1] - down_ys[pt2]) / (down_xs[pt2 + 1] - down_xs[pt2]);

			long double bup = up_ys[pt1] - kup * up_xs[pt1];
			long double bdown = down_ys[pt2] - kdown * down_xs[pt2];

			ans += (bup - bdown) * (logl(r) - logl(l));
		}

		if (down_xs[pt2 + 1] < up_xs[pt1 + 1]) pt2++;
		else pt1++;
	}

	ans /= up_xs[n];

	cout << fixed << setprecision(15) << ans << '\n';

	return 0;
}