#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int,int>> pos;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        pos.emplace_back(x, y);
    }

    vector<array<int,3>> ops;
    for (int i = n; i > 1; i--) {
        vector<int> cnt_r(n), cnt_c(n);
        for (auto& [px, py]: pos) {
            if (px < i && py < i) {
                cnt_r[px]++;
                cnt_c[py]++;
            }
        }

        // find all-0 column
        for (int j = 0; j < i - 1; j++) {
            if (cnt_c[j] == 0) {
                ops.push_back({2, j + 1, i});
                for (auto& [px, py]: pos) {
                    // swap column j and last column i
                    if (py == i - 1) {
                        py = j;
                    }
                }
                break;
            }
        }

        // find one row with '1'
        // swap with the last row
        for (int j = 0; j < i - 1; j++) {
            if (cnt_r[j] > 0) {
                ops.push_back({1, j + 1, i});
                for (auto& [px, py]: pos) {
                    if (px == j) {
                        px = i - 1;
                    } else if (px == i - 1) {
                        px = j;
                    }
                }
                break;
            }
        }
    }
    
    cout << ops.size() << endl;
    for (auto& [k, v1, v2]: ops) {
        cout << k << ' ' << v1 << ' ' << v2 << endl;
    }
    return 0;
}
