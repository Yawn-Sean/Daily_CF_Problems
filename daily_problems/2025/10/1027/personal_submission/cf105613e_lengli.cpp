#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (1LL * n * (n - 1) / 2 < k) {
        cout << -1;
        return 0;
    }

    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        if (1LL * i * (i + 1) / 2 > k) {
            for (int j = 0; j < i; ++j) ans.push_back(3);
            k -= 1LL * i * (i - 1) / 2;
            for (int j = 0; j < k; ++j) ans[j] = 6;
            if (k) ans.push_back(2);
            break;
        }
    }

    for (int x = 999997; (int)ans.size() < n; x -= 6) {
        if ((int)ans.size() < n) ans.push_back(x);
        if ((int)ans.size() < n) ans.push_back(x - 2);
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
