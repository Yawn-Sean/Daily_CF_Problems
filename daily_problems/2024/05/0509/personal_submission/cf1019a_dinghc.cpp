#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pc(n);
    vector<int> freq(m + 1, 0);
    for (auto&[p, c] : pc) {
        cin >> p >> c;
        freq[p]++;
    }
    ranges::sort(pc, [&] (auto& a, auto& b) {
        return a.second < b.second;
    });
    long long ans = LONG_LONG_MAX;
    // x > (n - x) / (m - 1) ==> x >= (n + m - 1) / m
    int mn = max(freq[1], (n + m - 1) / m);
    int mx = max(freq[1], (n + 1) / 2 + 1);
    for (int x = mn; x <= mx; x++) {
        long long cost = 0LL;
        int curr = freq[1];
        auto freq_cp = freq;
        vector<int> vis(n, false);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            auto& [p, c] = pc[i];
            if (p == 1 || freq_cp[p] < x) continue;
            if (curr < x) {
                vis[i] = true;
                curr++;
                freq_cp[p]--;
                cost += c;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                auto& [p, c] = pc[i];
                if (p == 1 || vis[i] == true) continue;
                if (curr < x) {
                    curr++;
                    freq_cp[p]--;
                    cost += c;
                } else {
                    if (freq_cp[p] >= x) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

