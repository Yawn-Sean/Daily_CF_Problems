#include <bits/stdc++.h>
using namespace std;

struct event {
    int pos;
    int tvid;
    int op_type;
};

void work() {
    int n; cin >> n;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        events.push_back({l, i, 0});
        events.push_back({r + 1, i, 1});
    }

    sort(events.begin(), events.end(), [](auto a, auto b){ return a.pos < b.pos; });
    set<int> tvs;
    vector<int> important(n);
    for (int i = 0; i < events.size();) {
        int pos = events[i].pos;
        while (i < events.size() && events[i].pos == pos) {
            if (events[i].op_type == 0) {
                tvs.insert(events[i].tvid);
            } else {
                tvs.erase(events[i].tvid);
            }
            i ++;
        }
        if (tvs.size() == 1) {
            important[*tvs.begin()] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!important[i]) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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