#include <bits/stdc++.h>
using namespace std;

static const long long mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<string> outs;

    while (t--) {
        long long n, l, r;
        cin >> n >> l >> r;

        long long block_cnt = n / l;

        if (block_cnt * r < n) {
            outs.emplace_back("-1");
            continue;
        }

        vector<long long> ans;
        long long remaining = n;

        for (long long i = 0; i < block_cnt; i++) {
            long long v = max(l, remaining - (block_cnt - 1 - i) * r);
            remaining -= v;
            ans.push_back(v);
        }

        // v = factorial(ans[0]) % mod
        long long v = 1;
        for (long long i = 1; i <= ans[0]; i++) {
            v = v * i % mod;
        }

        outs.push_back(to_string(ans.size()) + " " + to_string(v));

        long long cur = 1;
        for (long long x : ans) {
            outs.push_back(
                to_string(cur) + " " + to_string(cur + x - 1)
            );
            cur += x;
        }
    }

    for (size_t i = 0; i < outs.size(); i++) {
        cout << outs[i];
        if (i + 1 < outs.size()) cout << '\n';
    }

    return 0;
}
