#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), a = 0, b = 0, t = 0, mid = n / 2;
    string s, res;
    cin >> s;
    for (char c : s) {
        if (c == '(') {
            a++;
        } else if (c == ')') {
            b++;
        } 
    }
    if (a > mid || b > mid || n & 1) {
        cout << ":(\n";
    } else {
        bool found = false;
        int dif = mid - a, cnt = 0;
        rep(i, 0, n) {
            char c = s[i];
            if (c != '?') {
                res += c;
                if (c == '(') {
                    cnt++;
                } else {
                    cnt--;
                }
            } else {
                if (dif) {
                    cnt++;
                    dif--;
                    res += '(';
                } else {
                    cnt--;
                    res += ')';
                }
            }
            if (cnt == 0 && i != n - 1 || cnt < 0) {
                found = true;

                break;
            }
        }
        if (found) {
            cout << ":(\n";
        } else {
            cout << res << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
/*
https://codeforces.com/problemset/problem/1153/C
*/