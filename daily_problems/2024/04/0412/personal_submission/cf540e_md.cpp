#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    map<int, int> posToVal;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (!posToVal.contains(x)) {
            posToVal[x] = x;
        }
        if (!posToVal.contains(y)) {
            posToVal[y] = y;
        }
        swap(posToVal[x], posToVal[y]);
    }

    vector<int> idx_serial;
    vector<int> val_serial;
    for (const auto& [k, v] : posToVal) {
        idx_serial.push_back(k);
        val_serial.push_back(v);
    }

    auto find_idx = [&](int x) {
        return lower_bound(begin(idx_serial), end(idx_serial), x) - begin(idx_serial);
    };

    sort(begin(val_serial), end(val_serial));
    auto find_val = [&](int x) {
        return lower_bound(begin(val_serial), end(val_serial), x) - begin(val_serial);
    };

    int len = size(idx_serial);
    Fenwick<i64> fen(2 * len - 1);
    i64 ret = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (i + 1 < len) {
            auto p = 2 * i + 1;
            auto seg_len = idx_serial[i + 1] - idx_serial[i] - 1;
            ret += fen.sum(p) * seg_len;
            fen.add(p, seg_len);
        }
        int serialized_val = find_val(posToVal[idx_serial[i]]) * 2;
        ret += fen.sum(serialized_val);
        fen.add(serialized_val, 1);
    }

    cout << ret << endl;
    return 0;
}