#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

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

void solve() {
    int n; cin >> n;
    ht<int,int> mp;
    i64 res = 0;
    for (int i = 0; i < n; i++){
    	string s; cin >> s;
    	int v = 0;
    	for (auto &ch : s){
    		v ^= 1 << (ch - 'a');
    	}
    	res += mp[v];
    	mp[v]++;
    	for (int j = 0; j < 26; j++){
    		mp[v ^ (1 << j)]++;
    	}
    }
    cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}