#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include <cassert>
#include <vector>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

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

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<vector<int>> u = grid, d = grid, l = grid, r = grid;

	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (u[i][j]) u[i][j] = u[i - 1][j] + 1;
		}
	}

	for (int i = n - 2; i >= 0; i --) {
		for (int j = 0; j < n; j ++) {
			if (d[i][j]) d[i][j] = d[i + 1][j] + 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 1; j < n; j ++) {
			if (l[i][j]) l[i][j] = l[i][j - 1] + 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = n - 2; j >= 0; j --) {
			if (r[i][j]) r[i][j] = r[i][j + 1] + 1;
		}
	}

	auto solve = [&] (int x, int y) -> int {
		vector<int> v1, v2;

		while (x < n & y < n) {
			v1.emplace_back(min(d[x][y], r[x][y]) - 1);
			v2.emplace_back(min(u[x][y], l[x][y]) - 1);
			x ++, y ++;
		}
		
		int k = v1.size(), ans = 0;

		atcoder::fenwick_tree<int> fen(k + 1);
		vector<vector<int>> tmp(k + 1);

		for (int i = 0; i < k; i ++)
			tmp[i - v2[i]].emplace_back(i);
		
		for (int i = 0; i < k; i ++) {
			for (auto &j: tmp[i]) fen.add(j, 1);
			ans += fen.sum(0, i + v1[i] + 1);
		}

		return ans - k * (k - 1) / 2;
	};

	long long res = solve(0, 0);
	for (int i = 1; i < n; i ++)
		res += solve(0, i) + solve(i, 0);
	cout << res;

	return 0;
}