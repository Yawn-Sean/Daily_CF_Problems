#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n_) : n(n_), bit(n_ + 1, 0) {}

    void add(int i, long long v) {
        for (++i; i <= n; i += i & -i)
            bit[i] += v;
    }

    long long sum(int i) const {
        long long s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // sum[l..r]
    long long rsum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<string> outs;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int &x : nums) cin >> x;

        Fenwick fen(n + 1);
        long long ans = 0;
        vector<long long> diff;

        for (int x : nums) {
            long long v1 = fen.rsum(x + 1, n);
            long long v2 = fen.rsum(0, x - 1);

            ans += v1;
            diff.push_back(v2 - v1);

            fen.add(x, 1);
        }

        sort(diff.begin(), diff.end());

        vector<long long> res;
        res.reserve(diff.size() + 1);
        res.push_back(ans);

        for (long long x : diff)
            res.push_back(res.back() + x);

        ostringstream oss;
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) oss << ' ';
            oss << res[i];
        }
        outs.push_back(oss.str());
    }

    for (int i = 0; i < (int)outs.size(); i++) {
        if (i) cout << '\n';
        cout << outs[i];
    }

    return 0;
}
