#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <functional> // For std::function if needed, though not here

// Assuming std::gcd is available (C++17) or a custom implementation exists
// For this rewrite, we assume the environment supports the necessary functions.
// We also use a placeholder for the non-standard 'atcoder::internal::inv_gcd'.

using namespace std;

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = a%b;
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, LARGE = 1e9;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> pts;
		for (int i = 0; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			if (x || y) pts.emplace_back(x, y);
		}

		n = pts.size();

		{
			auto [dx, dy] = pts[0];
			int g = abs(gcd(dx, dy));
			dx /= g;
			dy /= g;

			bool flg1 = true, flg2 = true;
			for (auto &[x, y]: pts) {
				if (1ll * dx * y != 1ll * dy * x) flg1 = false;
				if (1ll * dx * x < 0 || 1ll * dy * y < 0) flg2 = false;
			}

			if (flg1) {
				if (flg2) {
					cout << "1\n";
					cout << dx << ' ' << dy << '\n';
				}
				else {
					cout << "2\n";
					cout << dx << ' ' << dy << '\n';
					cout << -dx << ' ' << -dy << '\n';
				}
				continue;
			}
		}

		{
			auto [x, y] = pts[0];
			for (int i = 1; i < n; i ++) {
				auto [nx, ny] = pts[i];
				if (1ll * nx * y > 1ll * ny * x)
					x = nx, y = ny;
			}

			bool flg = true;

			for (int i = 0; i < n; i ++) {
				auto [nx, ny] = pts[i];
				if (1ll * nx * y > 1ll * ny * x || (1ll * nx * y == 1ll * ny * x && (1ll * x * nx < 0 || 1ll * y * ny < 0))) {
					flg = false;
				}
			}

			if (flg) {
				int g = abs(gcd(x, y));
				x /= g;
				y /= g;

				int nx, ny;
				if (!y)
					nx = 0, ny = x;
				else {
					ny = inv_gcd(x, abs(y)).second;
					nx = (1ll * x * ny - 1) / y;
					if (1ll * nx * y > 1ll * ny * x)
						nx = -nx, ny = -ny;
				}

				cout << "2\n";
				cout << x << ' ' << y << '\n';
				cout << nx - 1ll * LARGE * x << ' ' << ny - 1ll * LARGE * y << '\n';
			}
			else {
				cout << "3\n";
				cout << "0 1\n";
				cout << "1 0\n";
				cout << "-1 -1\n";
			}
		}
	}

	return 0;
}
