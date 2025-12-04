#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    unsigned int umod() const { return _m; }

    unsigned int mul(unsigned int a, unsigned int b) const {

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned long long y = x * _m;
        return (unsigned int)(z - y + (z < y ? _m : 0));
    }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder


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
					ny = atcoder::internal::inv_gcd(x, abs(y)).second;
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