#include <bits/stdc++.h>
using namespace std;

void work() {
    long long v; cin >> v;
    long long g; cin >> g;

    vector<pair<long long, int>> g_p;
    {
        long long t = g;
        for (long long i = 2; i * i <= t; ++i) {
            if (t % i == 0) {
                int cnt = 0;
                while (t % i == 0) {
                    t /= i;
                    cnt ++;
                }
                g_p.push_back({i, cnt});
            }
        }
        if (t > 1) {
            g_p.push_back({t, 1});
        }
    }

    long long ans = 1e18;
    for (auto [p, cnt]: g_p) {
        long long t = v;
        long long cnt_p = 0;
        while (t) {
            t /= p;
            cnt_p += t;
        }
        ans = min(ans, cnt_p / cnt);
    }

    cout << ans << "\n";
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