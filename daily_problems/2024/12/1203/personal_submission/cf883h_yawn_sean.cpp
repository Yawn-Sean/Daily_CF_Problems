#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> mp;
    for (auto &c: s) mp[c] ++;

    vector<char> odds;
    for (auto &[k, v]: mp) {
        if (v & 1) {
            odds.emplace_back(k);
            mp[k] --;
        }
    }

    if (odds.empty()) {
        string res;
        for (auto &[k, v]: mp) {
            res += string(v / 2, k);
        }
        cout << "1\n";
        cout << res;
        reverse(res.begin(), res.end());
        cout << res;
        return 0;
    }

    for (int i = odds.size(); i <= n; i ++) {
        if (n % i == 0) {
            int length = n / i;
            if (length & 1) {
                vector<string> ans(i);
                int target = length / 2;

                for (int idx = 0; idx < i; idx ++) {
                    char c;
                    if (odds.size()) {
                        c = odds.back();
                        odds.pop_back();
                    }
                    else {
                        for (auto &[k, v]: mp) {
                            if (v > 0) {
                                c = k;
                                mp[c] --;
                                break;
                            }
                        }
                    }
                    string half;
                    int cur_len = 0;
                    vector<int> to_delete;

                    for (auto &[k, v]: mp) {
                        int val = min(v / 2, target - cur_len);
                        mp[k] -= val * 2;
                        if (mp[k] == 0) to_delete.emplace_back(k);
                        half += string(val, k);
                        cur_len += val;
                        if (cur_len == target) break;
                    }

                    for (auto &x: to_delete)
                        mp.erase(x);

                    ans[idx] += half;
                    ans[idx] += c;
                    reverse(half.begin(), half.end());
                    ans[idx] += half;
                }

                cout << i << '\n';
                for (auto &x: ans)
                    cout << x << ' ';
                return 0;
            }
        }
    }

    return 0;
}