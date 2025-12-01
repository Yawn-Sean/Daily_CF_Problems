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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		string s;
		cin >> s;

		vector<int> nums(2 * n);
		for (auto &v: nums) cin >> v;

		vector<vector<int>> path(n + 1);
		vector<int> parent(n + 1, -1), notes(2 * n), stk = {0};
		int pt = 1;

		for (int i = 0; i < 2 * n; i ++) {
			if (s[i] == '(') {
				parent[pt] = stk.back();
				path[stk.back()].emplace_back(pt);
				stk.emplace_back(pt);
				notes[i] = pt ++;
			}
			else stk.pop_back();
		}

		vector<int> ls(n + 1, 0), rs(n + 1, 0), depth(n + 1, 0);
		int tmstamp = 0;

		auto dfs = [&] (auto &self, int u) -> void {
			ls[u] = tmstamp ++;
			for (auto &v: path[u]) {
				depth[v] = depth[u] + 1;
				self(self, v);
			}
			rs[u] = tmstamp;
		};

		dfs(dfs, 0);

		vector<vector<int>> nth_parent(20, vector<int>(n + 1, -1));
		nth_parent[0] = parent;

		for (int i = 0; i < 19; i ++) {
			for (int j = 0; j <= n; j ++) {
				if (nth_parent[i][j] != -1) {
					nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
				}
			}
		}

		auto lca = [&] (int u, int v) -> int {
			if (depth[u] > depth[v]) swap(u, v);

			int d = depth[v] - depth[u];

			while (d) {
				int x = d & -d;
				v = nth_parent[__builtin_ctz(x)][v];
				d -= x;
			}

			if (u == v) return u;

			for (int i = 19; i >= 0; i --) {
				if (nth_parent[i][u] != nth_parent[i][v]) {
					u = nth_parent[i][u];
					v = nth_parent[i][v];
				}
			}

			return parent[u];
		};

		atcoder::fenwick_tree<long long> fen(n + 1);

		while (q --) {
			int t;
			cin >> t;

			if (t == 1) {
				int l1, r1, l2, r2, val;
				cin >> l1 >> r1 >> l2 >> r2 >> val;
				int u = notes[l1 - 1], v = notes[l2 - 1];
				int l = lca(u, v);
				fen.add(ls[l], val);
			}
			else {
				int l, r;
				cin >> l >> r;
				int u = notes[l - 1];
				cout << fen.sum(ls[u], rs[u]) + nums[l - 1] << '\n';
			}
		}
	}

	return 0;
}