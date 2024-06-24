#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


//0: no consecutive 1s, fibonacci
//1: at least 1 consecutive 1s
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {  /// use most bits rather than just the lowest ones
	const uint64_t C =
	    i64(2e18 * acos((long double)-1)) + 71;  // large odd number
	const int RANDOM = rng();
	i64 operator()(i64 x)
	    const {  /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};
template <class K, class V> using ht = gp_hash_table<K, V, chash>;



i64 mod;
ht<i64,i64> mp;
i64 fib(i64 n){
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (mp.find(n) != mp.end()) return mp[n];
	mp[n] = (fib((n + 1) / 2) * fib(n / 2) % mod + fib((n - 1) / 2) *  fib((n - 2) / 2) % mod) % mod;
	return mp[n];
}

i64 qpow(i64 a, i64 b){
	i64 res = 1;
	a = (a % mod + mod) % mod;
	for (; b; b >>= 1){
		if (b & 1) res = (a * res) % mod;
		a = (a * a) % mod;
	}
	return res;
}

void solve() {
	i64 n, k, l; cin >> n >> k >> l >> mod;
	if (l <= 60 && k >= (1LL << l)) {
		cout << "0\n";
		return;
	}

	i64 res = 1;
	int cnt = __builtin_popcountll(k);

	//calculate 0 case
	i64 zero = fib(n + 1);
	//cout << zero << "\n";
	res = res * qpow(zero, l - cnt) % mod;
	i64 one = ((qpow(2, n) - zero) % mod + mod) % mod;
	res = res * qpow(one, cnt) % mod;

	//cout << cnt <<" "<< zero <<" "<< one <<" "<< l - cnt << "\n";

	cout << res << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}