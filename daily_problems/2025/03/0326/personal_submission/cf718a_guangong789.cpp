#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    char s[200005];
    cin >> n >> k >> s;
    int start;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            start = i;
            break;
        }
    }
    int idx = 0;
    for (int i = start + 1; i < n; i++) {
        if (s[i] >= '5') {
            s[i] = '\0';
            s[i - 1]++;
            idx = i;
            break;
        }
    }
    if (idx != 0) {
        for (int i = idx - 1; i > start; i--) {
            if (s[i] > '9') {
                s[i] = '\0';
                s[i - 1]++;
                idx = i;
            } else {
                break;
            }
        }
        k--;
    }
    while (k--) {
        int tmp = idx;
        for (int i = idx - 1; i > start; i--) {
            if (s[i] >= '5') {
                s[i] = '\0';
                s[i - 1]++;
                idx = i;
                break;
            }
        }
        if (idx == tmp) {
            break;
        }
        for (int i = idx - 1; i > start; i--) {
            if (s[i] > '9') {
                s[i] = '\0';
                s[i - 1]++;
                idx = i;
            } else {
                break;
            }
        }
    }
    if (s[start] > '.') {
        s[start - 1]++;
        s[start] = '\0';
        for (int i = start - 1; i > 0; i--) {
            if (s[i] > '9') {
                s[i] = '0';
                s[i - 1]++;
            }
        }
        if (s[0] > '9') {
            cout << "1";
            s[0] = '0';
        }
    }
    cout << s;
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
