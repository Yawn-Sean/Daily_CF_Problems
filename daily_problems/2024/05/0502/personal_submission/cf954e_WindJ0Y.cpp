#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, T; cin >> n >> T;
    
    vector<pair<int, int>> t_and_a(n);
    for (int i = 0; i < n; i++) {
        cin >> t_and_a[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> t_and_a[i].first;
    }
    sort(t_and_a.begin(), t_and_a.end());

    long long total_wps = 0;
    long long tw = 0;
    for (int i = 0; i < n; i++) {
        total_wps += t_and_a[i].second;
        tw += 1ll * t_and_a[i].first * t_and_a[i].second;
    }

    auto fiter = t_and_a.begin();
    auto biter = t_and_a.rbegin(); 

    while (tw > total_wps * T) {
        auto [cur_t, cur_w] = *biter++;
        long long cur_tw = 1ll * cur_t * cur_w;
        if (tw - cur_tw >= (total_wps - cur_w) * T) {
            tw -= cur_tw;
            total_wps -= cur_w;
        } else {
            tw -= cur_tw;
            total_wps -= cur_w;
            double picked_w = 1.0 * (tw - total_wps * T) / (T - cur_t);
            double ans_total_wps = total_wps + picked_w;
            cout << ans_total_wps << endl;
            return;
        }
    }

    while (tw < total_wps * T) {
        auto [cur_t, cur_w] = *fiter++;
        long long cur_tw = 1ll * cur_t * cur_w;
        if (tw - cur_tw <= (total_wps - cur_w) * T) {
            tw -= cur_tw;
            total_wps -= cur_w;
        } else {
            tw -= cur_tw;
            total_wps -= cur_w;
            double picked_w = 1.0 * (tw - total_wps * T) / (T - cur_t);
            double ans_total_wps = total_wps + picked_w;
            cout << ans_total_wps << endl;
            return;
        }
    }

    cout << total_wps << endl;
    return;
}

int main(void) {
    
    ios::sync_with_stdio(false);
    
    cout << fixed << setprecision(15);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}