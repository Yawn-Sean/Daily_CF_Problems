#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    char s[50][50];
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            s[i][j] = 'A';
        }
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 25; j < 50; j++) {
            s[i][j] = 'B';
        }
    }
    for (int i = 25; i < 50; i++) {
        for (int j = 0; j < 25; j++) {
            s[i][j] = 'C';
        }
    }
    for (int i = 25; i < 50; i++) {
        for (int j = 25; j < 50; j++) {
            s[i][j] = 'D';
        }
    }
    // A 和 B 互填，C 和 D 互填
    for (int i = 1; i < 25; i += 2) {
        for (int j = 1; j < 24; j += 2) {
            if (b) {
                s[i][j] = 'B';
                b--;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i < 25; i += 2) {
        for (int j = 26; j < 49; j += 2) {
            if (a) {
                s[i][j] = 'A';
                a--;
            } else {
                break;
            }
        }
    }
    for (int i = 26; i < 50; i += 2) {
        for (int j = 1; j < 24; j += 2) {
            if (d) {
                s[i][j] = 'D';
                d--;
            } else {
                break;
            }
        }
    }
    for (int i = 26; i < 50; i += 2) {
        for (int j = 26; j < 49; j += 2) {
            if (c) {
                s[i][j] = 'C';
                c--;
            } else {
                break;
            }
        }
    }
    cout << 50 << " " << 50 << endl;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}