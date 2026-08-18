#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, s, e;
    cin >> k >> s >> e;
    vector<int> a(k - 1);
    iota(a.begin(), a.end(), 2);

    vector<array<int, 2>> ans;
    for (int i = k - 1; i >= 2; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] == i) {
                continue;
            }
            ans.push_back({1, a[j]});
        }
        ans.push_back({1, i});
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] == i) {
                continue;
            }
            ans.push_back({a[j], i});
        }
        a.pop_back(), a.pop_back(), a.push_back(k);
    }
    for (int i = 1; i < k; i++) {
        for (int j = 1; j < i; j++) {
            ans.push_back({i, j});
        }
        for (int j = i; j >= 1; j--) {
            ans.push_back({j, k});
        }
    }

    vector<int> idx(k + 1);
    idx[1] = s, idx[k] = e;
    int cnt = 1;
    for (int i = 2; i < k; i++) {
        while (cnt == s || cnt == e) {
            cnt++;
        }
        idx[i] = cnt++;
    }

    cout << ans.size() << "\n";
    for (const auto& [l, r] : ans) {
        cout << idx[l] << " " << idx[r] << "\n";
    }
    return 0;
}