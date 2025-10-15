#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &x : s) cin >> x;

    vector<i64> cnt(10);
    vector<int> can(10, 1);
    for (auto& x: s) {
        int m = x.size();
        i64 base = 1ll;
        for (int j = m - 1; j >= 0; j--) {
            if (j == 0) {
                can[x[j] - 'a'] = 0;
            }
            cnt[x[j] - 'a'] += base;
            base *= 10;
        }
    }

    vector<int> order(10);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return cnt[a] > cnt[b];
    });

    i64 ans = 0;
    vector<int> used(10);
    for (int i = 0; i < 10; i++) {
        if (cnt[order[i]] > 0 && can[order[i]]) {
            used[order[i]] = 1;
            break;
        }
    }

    for (int i = 1, j = 0; i < 10 && j < 10; j++) {
        if (used[order[j]]) {
            continue;
        }
        ans += 1ll * i * cnt[order[j]];
        used[order[j]] = 1;
        i++;
    }
    cout << ans;
    return 0;
}
