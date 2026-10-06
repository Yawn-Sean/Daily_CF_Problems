#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a(1 << n);
    for (auto& x : a) {
        cin >> x;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if ((i >> k & 1) || (j == k)) {
                    continue;
                }
                if (a[i | (1 << j)] + a[i | (1 << k)] < a[i] + a[i | (1 << j) | (1 << k)]) {
                    cout << (i | (1 << j)) << " " << (i | (1 << k)) << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1";
    return 0;
}
