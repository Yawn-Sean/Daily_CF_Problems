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
    string s;
    cin >> s;
    int n = s.size(), i, j, cnt = 0, res = 0, cur;
    rep(i, 0, n) {
        if (s[i] == '1') {
            cur = 0;
            for (int j = i; j < n && j <= i + 20; j++) {
                cur = cur * 2 + s[j] - '0';
                if (cur > j - cnt + 1) {
                    break;
                }
                ++res;
            }
            cnt = i + 1;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/contest/1217/problem/C
*/