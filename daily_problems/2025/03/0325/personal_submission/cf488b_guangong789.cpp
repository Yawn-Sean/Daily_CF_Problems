#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    ranges::sort(c);
    if (n == 0) {
        cout << "YES\n";
        cout << "1\n" << "1\n" << "3\n" << "3\n";
    } else if (n == 4) {
        if (accumulate(c.begin(), c.end(), 0) / 4 == (c[1] + c[2]) / 2 && (c[1] + c[2]) / 2 == (c[3] - c[0])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (n == 1) {
        cout << "YES\n";
        cout << c[0] << '\n' << 3 * c[0] << '\n' << 3 * c[0] << '\n';
    } else {
        if (n == 2) {
            if (3 * c[0] == c[1]) {
                cout << "YES\n";
                cout << c[1]-c[0] << '\n' << c[1]-c[0] << '\n';
            } else {
                int d1 = 2*c[0]-c[1], d2 = c[1]-2*c[0];
                if (d1 > 0 && 2*c[0]+d1 > 0) {
                    cout << "YES\n";
                    cout << 2*c[0]+d1 << '\n' << 3*c[0] << '\n';
                    return;
                } else if (d2 > 0 && 2*c[0]-d2 > 0) {
                    cout << "YES\n";
                    cout << 2*c[0]-d2 << '\n' << 3*c[0] << '\n';
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            if (3*c[0] == c[2]) {
                cout << "YES\n";
                cout << 2*(c[2]-c[0])-c[1] << '\n';
            } else {
                int d = 2*c[0] - c[1];
                if (3*(c[1]+c[0]) == 4*c[2]) {
                    cout << "YES\n";
                    cout << c[2]/3 << '\n';
                    return;
                } else if (c[2] == 2*c[0]+d) {
                    cout << "YES\n";
                    cout << 3*c[0] << '\n';
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}