#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 200001;
int lefts[MXN];
int rights[MXN];
int costs[MXN];
array<int, 3> events[MXN*2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        lefts[i] = l;
        rights[i] = r;
        costs[i] = c;
        events[2 * i] = array<int, 3>{l, 0, i};
        events[2 * i + 1] = array<int, 3>{r, 1, i};
    }

    sort(events, events + 2 * n);

    int ans = INT_MAX;
    map<int, int> mp;
    for (int i = 0; i < 2*n; i++) {
        auto& [pos, t, idx] = events[i];
        if (t == 0) {
            auto it = mp.find(x - (rights[idx] - lefts[idx] + 1));
            if (it != mp.end()) {
                ans = min(ans, costs[idx] + it->second);
            }
        } else {
            int dura = rights[idx] - lefts[idx] + 1;
            auto it = mp.find(dura);
            if (it != mp.end()) {
                it->second = min(costs[idx], it->second);
            } else {
                mp[dura] = costs[idx];
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";

    return 0;
}

