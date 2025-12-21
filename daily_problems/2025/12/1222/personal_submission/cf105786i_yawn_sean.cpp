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

    int M = 3e5;
    vector<int> prime_factor(M + 1);

    iota(prime_factor.begin(), prime_factor.end(), 0);
    for (int i = 2; i <= M; i ++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= M; j += i) {
                prime_factor[j] = i;
            }
        }
    }

    auto get_prime_factors = [&] (int x) -> vector<int> {
        vector<int> ans;
        while (x > 1) {
            int p = prime_factor[x];
            ans.emplace_back(p);
            while (x % p == 0) x /= p;
        }
        return ans;
    };

    int t;
    cin >> t;

    vector<int> vis(M + 1, -1), vis_target(M + 1, -1);

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &v: nums) cin >> v;

        int ans = 0, to_delete = 0;

        for (int i = 0; i < n; i ++) {
            int x = nums[i];
            auto tmp = get_prime_factors(x);

            bool flg = true;
            int pos = i;

            for (auto &v: tmp) {
                if (vis[v] != -1) {
                    pos = min(pos, vis[v]);
                    flg = false;
                }
                else vis[v] = i;
            }

            if (flg) {
                ans ++;
                for (auto &v: tmp) vis_target[v] = i;
            }
            else {
                unordered_set<int> nvis;
                for (auto &v: tmp) {
                    if (vis_target[v] > pos) {
                        nvis.insert(vis_target[v]);
                    }
                }
                to_delete = max(to_delete, (int)nvis.size());
            }
        }

        cout << ans - to_delete << '\n';

        for (auto &x: nums) {
            for (auto &v: get_prime_factors(x)) {
                vis[v] = -1;
                vis_target[v] = -1;
            }
        }
    }

	return 0;
}