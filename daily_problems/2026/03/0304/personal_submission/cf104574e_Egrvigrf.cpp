#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    vector<int> a(52), b(52);
    for (int i = 0; i < 52; i++) {
        cin >> a[i];
    }

    b = a;
    bool f = 0;
    do {
        vector<int> c, d, e;
        for (int i = 0; i < 26; i++) {
            c.push_back(a[i]);
        }
        for (int i = 26; i < 52; i++) {
            d.push_back(a[i]);
        }
        for (int i = 0; i <= 25; i++) {
            e.push_back(c[i]);
            e.push_back(d[i]);
        }
        a = e;

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] == 1) {
                sum++;
            }
        }
        if (sum == 4) {
            f = 1;
            break;
        }
    } while (a != b);
    if (f) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}