#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int x = 0, y = 0;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'U') {
            y++;
        } else {
            y--;
        }
        int rx = 0, ry = 0;
        for (int j = 0; j < s.length(); j++) {
            int a = rx, b = ry;
            if (s[j] == 'R') {
                rx++;
            } else if (s[j] == 'L') {
                rx--;
            } else if (s[j] == 'U') {
                ry++;
            } else {
                ry--;
            }
            if (rx == x && ry == y) {
                rx = a, ry = b;
            }
        }
        if (rx == 0 && ry == 0) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << x << ' ' << y << endl;
    } else {
        cout << 0 << ' ' << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}