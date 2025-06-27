#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> cnt(8);
    cnt[0] = 1;
    cnt[7] = 2;
    n -= 2;

    for (int i = 0; i < 8; i++) {
        int x = min(8 - cnt[i], n);
        n -= x;
        cnt[i] += x;
    }

    int cur = 1;
    for (int i = 0; i < 7; i++) {
        if (cnt[i] > 0) {
            vector<int> v = {cur};
            for (int j = 1; j <= 8; j++) {
                if (j != cur && v.size() < cnt[i]) {
                    v.emplace_back(j);
                }
            }
            // 防止提前走到最后一列
            if (cnt[i] == 8) {
                swap(v[6], v[7]);
            }
            for (auto& x: v) {
                cout << (char)('a' + i) << x << ' ';
            }
            cur = v.back();
        }
    }

    vector<int> v = {cur};
    for (int j = 1; j <= 8; j++) {
        if (j != cur && v.size() < cnt[7]) {
            v.emplace_back(j);
        }
    }
    v.back() = 8;
    for (auto& x: v) {
        cout << (char)('a' + 7) << x << ' ';
    }

    return 0;
}
