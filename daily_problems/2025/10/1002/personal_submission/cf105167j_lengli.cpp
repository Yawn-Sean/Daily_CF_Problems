#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, int delta) {            // idx: 0-based
        for (int i = idx + 1; i <= n; i += i & -i) bit[i] += delta;
    }
    int sumPrefix(int idx) const {            // sum of [0..idx], idx: 0-based
        int res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
    int sumRange(int l, int r) const {        // sum of [l..r], inclusive
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};

static long long countInversions(const vector<int>& a) {
    int n = (int)a.size();
    Fenwick fw(n);
    long long inv = 0;
    for (int i = n - 1; i >= 0; --i) {
        // number of elements < a[i] among suffix already added
        inv += fw.sumRange(0, a[i] - 1);
        fw.add(a[i], 1);
    }
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;

        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        long long best = 1LL * n * n;

        // Scheme A
        {
            vector<int> tmp(n);
            int evenPtr = 2, oddPtr = 1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == n / 2) tmp[i] = 0;
                else if (nums[i] == n / 2 + 1) tmp[i] = n - 1;
                else if (nums[i] < n / 2) { tmp[i] = evenPtr; evenPtr += 2; }
                else { tmp[i] = oddPtr; oddPtr += 2; }
            }
            best = min(best, countInversions(tmp));
        }

        // Scheme B
        {
            vector<int> tmp(n);
            int evenPtr = 2, oddPtr = 1;
            swap(evenPtr, oddPtr); 
            for (int i = 0; i < n; ++i) {
                if (nums[i] == n / 2) tmp[i] = n - 1;
                else if (nums[i] == n / 2 + 1) tmp[i] = 0;
                else if (nums[i] < n / 2) { tmp[i] = evenPtr; evenPtr += 2; }
                else { tmp[i] = oddPtr; oddPtr += 2; }
            }
            best = min(best, countInversions(tmp));
        }

        cout << 1LL * n * n / 2 - 1 << ' ' << best << '\n';
    }

    return 0;
}
