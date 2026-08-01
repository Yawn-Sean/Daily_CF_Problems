#include <bits/stdc++.h>
using namespace std;
#define int long long

void run_case() {
    int n; cin >> n;
    string s; cin >> s; s = '.' + s;
    bool op = true;
    if (s[1] == '0') {
        cout << -1; return;
    }
    if (n == 1) {
        cout << "a"; return;
    }

    auto check = [&]() {
        for (int i = 2; i < n; i++) {
            if (s[i] == '1') return false;
        }
        if (s[n] == '0') return false;
        return true;
    };

    if (n == 2) {
        if (s[2] == '1') cout << "aa";
        else cout << "ab";
        return;
    }

    if (check()) {
        if (n & 1) {
            for (int i = 1; i <= n / 2; i++) cout << "a"; cout << "b";
            for (int i = 1; i <= n / 2; i++) cout << "a"; return;
        }
        else {
            for (int i = 1; i < n / 2; i++) cout << "a"; cout << "bb";
            for (int i = 1; i < n / 2; i++) cout << "a"; return;
        }
    }


    for (int i = 5; i <= n; i+=2) {
        if (s[i] != s[i-2]) {
            op = false;
        }
    }
    for (int i = 4; i <= n; i+=2) {
        if (s[i] != s[i-2]) {
            cout << -1; return;
        }
    }
    if (!op) {
        cout << -1; return;
    }
    if (n >= 3) {
        if (s[3] == '0' && s[2] == '1') {
            cout << -1; return;
        }
        if (s[3] == '0' && s[2] == '0') {
            for (int i = 1; i < n; i++) cout << "a";
            cout << "b"; return;
        }
        if (s[3] == '1' && s[2] == '0') {
            bool c = 1;
            while (n--) {
                if (c) cout << "a";
                else cout << "b";
                c ^= 1;
            }
            return;
        }
        if (s[3] == '1' && s[2] == '1') {
            for (int i = 1; i <= n; i++) cout << "a";
            return;
        }
    }


}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        cout << '\n';
        // cout << endl;
    }
    return 0;
}