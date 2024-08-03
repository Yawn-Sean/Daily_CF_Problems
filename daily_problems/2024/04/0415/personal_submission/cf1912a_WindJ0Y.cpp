#include <bits/stdc++.h>
using namespace std;

void work() {
    int64_t curv; cin >> curv;
    int gpcnt; cin >> gpcnt;

    vector<queue<pair<int64_t, int64_t>>> gps;
    priority_queue<pair<int64_t, int>> pq;

    while(gpcnt--) {
        queue<pair<int64_t, int64_t>> curq;
        int nsz; cin >> nsz;
        while (nsz--) {
            int v; cin >> v;
            if (!curq.size() || (v < 0 && curq.back().second > 0)) {
                curq.emplace(v, v);
            } else {
                curq.back().second += v;
                curq.back().first = min(curq.back().first, curq.back().second); 
            }
        }
        if (curq.front().second > 0) {
            gps.emplace_back(curq);
            pq.emplace(curq.front().first, gps.size() - 1);
        }
    }

    while (!pq.empty()) {
        auto [minv, pid] = pq.top(); pq.pop();
        if (curv + minv < 0) {
            break;
        }
        auto &curq = gps[pid];
        int64_t addv = curq.front().second;
        if (addv < 0) {
            continue;
        }
        curv += addv;
        curq.pop();
        if (curq.size()) {
            pq.emplace(curq.front().first, pid);
        }
    }

    cout << curv << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}