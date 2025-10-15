#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9+5;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, tmp;
    cin >> n;
    map<int, vector<int>> vp;
    vector<int> ans(2 * n, 0);
    map<int, int> mp;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> tmp;
        mp[tmp]++;
        vp[tmp].emplace_back(i);
    }
    int c1 = 0, c2 = 0, turn = 0;
    for (auto& [k, v] : mp) {
        if (v == 1) {
            if (turn) {
                c1++;
            }
            else {
                c2++;
            }
            turn ^= 1;
        } else {
            c1++, c2++;
        }
    }
    int mx = c1 * c2;
    cout << mx << '\n';
    vector<pair<int, int>> cnts(mp.begin(), mp.end());
    sort(cnts.begin(), cnts.end(), [&](const auto& p1, const auto& p2) {
        return p1.second > p2.second;
    });

    int cnt1 = 0, cnt2 = 0;
    for (auto [key, times] : cnts) {
        if (times == 1) {
            int idx = vp[key].back();
            if (cnt1 < n) {
                ans[idx] = 1;
                cnt1++;
            } else {
                ans[idx] = 2;
                cnt2++;
            }
            vp.erase(key);
            continue;
        }
        if (times % 2 == 0) {
            int limit = times / 2;
            for (int i = 0; i < times; ++i) {
                int idx = vp[key][i];
                if (i < limit && cnt1 < n) {
                    ans[idx] = 1;
                    cnt1++;
                } else {
                    ans[idx] = 2;
                    cnt2++;
                }
            }
        }
        if (times % 2) {
            int used1 = 0, used2 = 0;
            for (int i = 0; i < times; ++i) {
                int idx = vp[key][i];
                if (!used1) {
                    ans[idx] = 1;
                    cnt1++;
                    used1 = 1;
                } else if (!used2) {
                    ans[idx] = 2;
                    cnt2++;
                    used2 = 1;
                } else {
                    if (cnt1 < cnt2 && cnt1 < n) {
                        ans[idx] = 1;
                        cnt1++;
                    } else {
                        ans[idx] = 2;
                        cnt2++;
                    }
                }
            }
        }
    }
    for (int i : ans) {
        cout << i << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
