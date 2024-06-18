#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200'003;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs(n);
    vector<array<int, 3>> ev(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].first >> segs[i].second;
        ev[i * 2] = array<int, 3>{segs[i].first, i, 0};
        ev[i * 2 + 1] = array<int, 3>{segs[i].second + 1, i, 1};
    }
    ev[n * 2] = array<int, 3>{MXN, -1, 0};
    ranges::sort(ev);
    set<pair<int, int>> sorted;
    set<int> removed;
    for (int i = 0, cur_cnt = 0; i < n * 2; i++) {
        auto&[cur_p, cur_j, cur_t] = ev[i];
        if (cur_t == 0) {
            cur_cnt += 1;
            sorted.insert(make_pair(segs[cur_j].second, cur_j));
        } else {
            if (removed.find(cur_j) == removed.end()) {
                cur_cnt -= 1;
                auto it = sorted.find(make_pair(segs[cur_j].second, cur_j));
                if (it != sorted.end()) sorted.erase(it);
            }
        }
        if (cur_p != ev[i + 1][0]) {
            while (cur_cnt > k) {
                auto it = prev(sorted.end());
                auto [right, j] = *it;
                sorted.erase(it);
                cur_cnt--;
                removed.insert(j);
            }
        }
    }
    cout << removed.size() << "\n";
    for (auto& i : removed) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}

