#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int segs = 0, dots = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            dots++;
            cur++;
        } else {
            if (cur) {
                segs++;
                cur = 0;
            }
        }
    }
    if (cur) segs++;
    int x;
    char c;
    for (int i = 0; i < m; i++) {
        cin >> x >> c;
        x--;
        if (s[x] == '.' && c != '.') {
            dots--;
            if (x - 1 >= 0 && s[x - 1] == '.' && x + 1 < n && s[x + 1] == '.') {
                segs++;
            } else if ((x == 0 || s[x - 1] != '.') && (x == n - 1 || s[x + 1] != '.')) {
                segs--;
            }
            s[x] = c;
        } else if (s[x] != '.' && c == '.') {
            dots++;
            if ((x == 0 || s[x - 1] != '.') && (x == n - 1 || s[x + 1] != '.')) {
                segs++;
            } else if (x - 1 >= 0 && s[x - 1] == '.' && x + 1 < n && s[x + 1] == '.') {
                segs--;
            }
            s[x] = c;
        }
        cout << dots - segs << "\n";
    }
    return 0;
}

