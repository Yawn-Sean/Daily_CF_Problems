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
    ht<int,int> freq;

    for (int i = 0; i < n; i++){
    	int x; cin >> x;
    	freq[x]++;
    }
    vector<int> group;
    for (auto &[k, v] : freq){
    	group.push_back(v);
    }
    sort(group.begin(), group.end());
    group.erase(unique(group.begin(), group.end()), group.end());
    int best = 2;
    for (int i = group[0] + 1; i >= 3; i--){
    	//i or i - 1
    	bool ok = true;
    	for (int k = 2; k < i; k++){
    		//minimum this time
    		if (k * (i - 1) > (k - 1) * i){
    			auto it = upper_bound(group.begin(), group.end(), (k - 1) * i);
    			if (it != group.end() && *it < k * (i - 1)) {
    				ok = false;
    				break;
    			}
    		}
    		if (k * i >= group.back()) break;
    	}
    	if (ok) {
    		best = i;
    		break;
    	}
    }
    i64 res = 0;
    for (auto &[k, v] : freq){
    	res += (v + best - 1) / best;
    }
    cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}