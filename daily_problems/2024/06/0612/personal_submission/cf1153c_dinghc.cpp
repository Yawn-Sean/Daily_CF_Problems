#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0, q = 0;
    for (auto& c : s) {
        if (c == '(') {
            l++;
        } else if (c == ')') {
            r++;
        } else {
            q++;
        }
    }
    int t = q + r - l;
    if (t < 0 || t % 2) {
        cout << ":(\n";
    } else {
        int a = t / 2;
        if (a > q) {
            cout << ":(\n";
        } else {
            bool solvable = true;
            int d = 0;
            for (int i = 0; i < n; i++) {
                auto& c = s[i];
                if (c == '(') {
                    d++;
                } else if (c == ')') {
                    d--;
                } else {
                    if (a-- > 0) {
                        d++;
                        c = '(';
                    } else {
                        d--;
                        c = ')';
                    }
                }
                if (i < n - 1 && d <= 0) {
                    solvable = false;
                    break;
                }
            }
            if (solvable) {
                cout << s << "\n";
            } else {
                cout << ":(\n";
            }
        }
    }
    return 0;
}

