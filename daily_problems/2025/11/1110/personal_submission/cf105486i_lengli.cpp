#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;        
    int size;   
    vector<int> seg; 

    static int gcdOp(int a, int b) { return std::gcd(a, b); }

    SegTree() : n(0), size(0) {}
    SegTree(const vector<int>& a) { build(a); }

    void build(const vector<int>& a) {
        n = (int)a.size();
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(size << 1, 0); 
        for (int i = 0; i < n; ++i) seg[size + i] = a[i];
        for (int i = size - 1; i >= 1; --i) {
            seg[i] = gcdOp(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    void set(int p, int v) {
        int idx = size + p;
        seg[idx] = v;
        idx >>= 1;
        while (idx >= 1) {
            seg[idx] = gcdOp(seg[idx << 1], seg[idx << 1 | 1]);
            idx >>= 1;
        }
    }
    int all_prod() const { return seg[1]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXM = 200000;
    vector<int> divCount(MAXM + 1, 0);
    for (int i = 1; i <= MAXM; ++i) {
        for (int j = i; j <= MAXM; j += i) {
            ++divCount[j];
        }
    }

    int T;
    if (!(cin >> T)) return 0;
    vector<long long> outputs; 

    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        vector<int> vals(n, 0);
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) vals[i] = i;
            else vals[i] = 0;
        }
        SegTree seg(vals);
        auto getCount = [&](int g) -> int {
            if (g == 0) return n;
            if (g <= MAXM) return divCount[g];
            int cnt = 0;
            for (int d = 1; (long long)d * d <= g; ++d) {
                if (g % d == 0) {
                    cnt++;
                    if (d * d != g) cnt++;
                }
            }
            return cnt;
        };

        outputs.push_back(getCount(seg.all_prod()));

        for (int qi = 0; qi < q; ++qi) {
            int idx, val;
            cin >> idx >> val;
            --idx; 
            nums[idx] = val;

            if (idx > 0) {
                int newv = (nums[idx] < nums[idx - 1]) ? idx : 0;
                if (newv != vals[idx]) {
                    vals[idx] = newv;
                    seg.set(idx, newv);
                }
            }
            if (idx + 1 < n) {
                int newv = (nums[idx + 1] < nums[idx]) ? (idx + 1) : 0;
                if (newv != vals[idx + 1]) {
                    vals[idx + 1] = newv;
                    seg.set(idx + 1, newv);
                }
            }
            outputs.push_back(getCount(seg.all_prod()));
        }
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        cout << outputs[i] << '\n';
    }

    return 0;
}
