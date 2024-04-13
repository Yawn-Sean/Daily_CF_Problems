#include <bits/stdc++.h>
#include <ranges>
using namespace std;

using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    // set num[x] = v
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    // sum of [0, x)    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    // rangeSum [l, r)
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));

    vector<int> ids(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](int i, int j) {
        return a[i] < a[j];
    });
    
    Fenwick<int> fen(n);
    for (int i = 0; i < n; ++i) {
        fen.add(i, 1);
    }

    int last_pos = 0, end = 0;
    i64 ret = 0;
    for (int start = 0; start < n; start = end) {
        int nxt = -1;
        int fliped = false;
        int fliped_nxt = -1;
        while (end < n && a[ids[start]] == a[ids[end]]) {
            nxt = max(nxt, ids[end]);
            if (ids[end] < last_pos) {
                fliped = true;
                fliped_nxt = max(fliped_nxt, ids[end]);
            }
            ++end;
        }
        
        if (fliped) {
            ret += fen.rangeSum(last_pos, n) + fen.rangeSum(0, fliped_nxt + 1);
            last_pos = fliped_nxt + 1;
        } else {
            ret += fen.rangeSum(last_pos, nxt + 1);
            last_pos = nxt + 1;
        }

        for (int k = start; k < end; ++k) {
            fen.add(ids[k], -1);
        }
    }
    cout << ret << endl;

    return 0;
}