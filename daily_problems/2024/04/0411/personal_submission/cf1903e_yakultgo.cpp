#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;
    vector<pair<int, int>> a(n);
    set<int> cnt[2];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if ((a[i].first + a[i].second) % 2 == 0)
            cnt[0].insert(i + 1);
        else
            cnt[1].insert(i + 1);
    }
    auto cle = [&](int k) {
        if (cnt[k].size()) {
            cout << *cnt[k].begin() << endl;
            cnt[k].erase(cnt[k].begin());
        } else {
            cout << *cnt[k ^ 1].begin() << endl;
            cnt[k ^ 1].erase(cnt[k ^ 1].begin());
        }
    };
    int flag = (sx + sy) % 2;
    if (cnt[flag].size() >= cnt[flag ^ 1].size()) {
        cout << "First" << endl;
        for (int i = 0; i < n / 2; i++) {
            // 优先拿flag^1
            cle(flag ^ 1);
            int x;
            cin >> x;
            int k = (a[x - 1].first + a[x - 1].second) % 2;
            cnt[k].erase(x);
            cout << endl;
        }
        if (n % 2 == 1) cle(flag ^ 1);
    } else {
        cout << "Second" << endl;
        for (int i = 0; i < n / 2; i++) {
            // 优先拿flag
            int x;
            cin >> x;
            int k = (a[x - 1].first + a[x - 1].second) % 2;
            cnt[k].erase(x);
            // 优先拿flag
            cle(flag);
            cout << endl;
        }
        if (n % 2 == 1) {
            int x;
            cin >> x;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}