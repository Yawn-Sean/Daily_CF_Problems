#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> apps(n);
    // x应用所在的位置 pos
    // mp[x] x位置上应用的编号
    vector<int> pos(n + 1), mp(n + 1);
    int idx = 0;
    for (auto&x: apps) {
        cin >> x;
        pos[x] = idx;
        mp[idx] = x;
        idx++;
    }

    vector<int> b(m);
    for (auto&x : b) {
        cin >> x;
    }

    i64 ans = 0;
    for (auto&idx : b) {
        ans += (pos[idx] / k) + 1;

        int cur = pos[idx];
        int pre = max(0, cur - 1);
        int pre_app = mp[pre];

        pos[pre_app] = cur;
        pos[idx] = pre;
        mp[pre] = idx;
        mp[cur] = pre_app;
    }

    cout << ans << "\n";
    return 0;
}
