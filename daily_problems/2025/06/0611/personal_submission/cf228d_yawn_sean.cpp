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

    void init(vector<T> &vals) {
        for (int i = 0; i < _n; i ++)
            data[i] = vals[i];
        for (int i = 0; i < _n; i ++) {
            int j = i | (i + 1);
            if (j < _n) data[j] += data[i]; 
        }
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int q;
    cin >> q;

    vector<array<int, 4>> queries(q);
    for (int i = 0; i < q; i ++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            queries[i] = {1, k - 1, u, 0}; 
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            queries[i] = {2, l - 1, r - 1, k};
        }
    }
    
    atcoder::fenwick_tree<long long> fen(n);
    vector<long long> tmp(n);

    vector<long long> ans(q, -1);
    for (int i = 2; i <= 6; i ++) {
        vector<int> weight(2 * i - 2);
        for (int j = 0; j < i - 1; j ++)
            weight[j] = j + 1;
        for (int j = i - 1; j < 2 * i - 2; j ++)
            weight[j] = 2 * i - 1 - j;
        int l = 2 * i - 2;

        for (int start = 0; start < l; start ++) {
            for (int j = 0; j < n; j ++)
                tmp[j] = 1ll * nums[j] * weight[(j - start + l) % l];
            fen.init(tmp);
            for (int j = 0; j < q; j ++) {
                auto &q = queries[j];
                if (q[0] == 1) {
                    int k = q[1], u = q[2];
                    fen.add(k, 1ll * u * weight[(k - start + l) % l] - tmp[k]);
                    tmp[k] = 1ll * u * weight[(k - start + l) % l];
                }
                else if (q[1] % l == start && q[3] == i) {
                    ans[j] = fen.sum(q[1], q[2] + 1);
                }
            }
        }
    }

    for (auto &x: ans)
        if (x != -1) cout << x << '\n';

    return 0;
}