#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, q; cin >> n >> q;
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; i ++) {
        cin >> qs[i].first >> qs[i].second;
    }

    vector<int> posv(n + 2);
    for (auto [s, e] : qs) {
        for (int i = s; i <= e; i ++) {
            posv[i] ++;
        }
    }

    int tans = n;

    for (int dpos = 0; dpos < q; dpos ++) {
        auto [ds, de] = qs[dpos];
        for (int i = ds; i <= de; i ++) {
            posv[i] --;
        }

        int zcnt = 0;
        vector<int> onecnt(n + 2);
        for (int i = 1; i <= n; i ++) {
            onecnt[i] = onecnt[i - 1] + (posv[i] == 1);
            zcnt += (posv[i] == 0);
        }

        for (int i = 0; i < q; i ++) {
            if (i == dpos) {
                continue;
            }
            auto [s, e] = qs[i];
            int rcnt = onecnt[e] - onecnt[s - 1];
            tans = min(tans, rcnt + zcnt);
        }

        for (int i = ds; i <= de; i ++) {
            posv[i] ++;
        }
    }

    tans = n - tans;
    cout << tans << endl;

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