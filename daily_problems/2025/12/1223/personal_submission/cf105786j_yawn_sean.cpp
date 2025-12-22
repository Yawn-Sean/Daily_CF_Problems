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

    int t;
    cin >> t;

    long long inf = 1e18;

    auto f = [&] (long long x, long long l, long long r, long long c) -> long long {
        if (x < l) return l - x + c;
        if (x > r) return x - r + c;
        return c;
    };

    while (t --) {
        int n;
        cin >> n;

        vector<long long> nums(n);
        for (auto &v: nums) cin >> v;

        vector<long long> ls = nums, rs = nums, cost(n, 0);

        while (n > 1) {
            vector<long long> nls, nrs, ncost;

            for (int i = 0; i < n; i += 4) {
                long long l = 0, r = 0, cur = inf;

                for (int j = i; j < i + 4; j ++) {
                    long long v;

                    v = 0;
                    for (int k = i; k < i + 4; k ++)
                        v += f(ls[j], ls[k], rs[k], cost[k]);
                    
                    if (v < cur) {
                        cur = v;
                        l = ls[j];
                        r = ls[j];
                    }
                    else if (v == cur) {
                        l = min(l, ls[j]);
                        r = max(r, ls[j]);
                    }

                    v = 0;
                    for (int k = i; k < i + 4; k ++)
                        v += f(rs[j], ls[k], rs[k], cost[k]);
                    
                    if (v < cur) {
                        cur = v;
                        l = rs[j];
                        r = rs[j];
                    }
                    else if (v == cur) {
                        l = min(l, rs[j]);
                        r = max(r, rs[j]);
                    }
                }
                nls.emplace_back(l);
                nrs.emplace_back(r);
                ncost.emplace_back(cur);
            }

            n /= 4;
            ls.swap(nls);
            rs.swap(nrs);
            cost.swap(ncost);
        }

        cout << f(0, ls[0], rs[0], cost[0]) << '\n';
    }

	return 0;
}