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

    int n;
    cin >> n;

    vector<int> nums(n + 1);
    for (auto &v: nums) cin >> v;

    for (int h = 0; h < n; h ++) {
        if (nums[h] > 1 && nums[h + 1] > 1) {
            cout << "ambiguous\n";

            int total = 0;
            for (auto &v: nums) total += v;

            vector<int> depth(total, 0), chosen_node(n + 1, 0);
            int pt = 0;

            for (int i = 0; i < total; i ++) {
                while (nums[pt] == 0) pt ++;
                depth[i] = pt, nums[pt] --, chosen_node[depth[i]] = i;
            }

            vector<int> ans(total, 0);

            for (int i = 1; i < total; i ++)
                ans[i] = chosen_node[depth[i] - 1] + 1;
            
            for (auto &v: ans) cout << v << ' '; cout << '\n';

            for (int i = 1; i < total; i ++) {
                if (depth[i] == h + 1) {
                    ans[i] = chosen_node[depth[i] - 1];
                    break;
                }
            }

            for (auto &v: ans) cout << v << ' '; cout << '\n';
            return 0;
        }
    }

    cout << "perfect";

    return 0;
}