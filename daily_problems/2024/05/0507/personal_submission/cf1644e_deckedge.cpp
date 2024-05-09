#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}
 
void solve() {
    int n = red();  
    string s;  
    cin >> s; 

    int m = s.size(), sx = 0, sy = 0;
    bool flag = false;
    rep(i, 0, m) {
        if (s[i] == 'R') {
            sy++;
        } else {
            sx++;
        } 
    }
    int64_t res = (int64_t)(n - sx) * (n - sy) + m;
    rep(i, 1, m) {
        if (s[i] != s[i - 1]) {
            flag = true;
        }
        if (flag) {
            res += n - (s[i] == 'R' ? sx : sy) - 1;
        }
    }
    if (flag) {
        cout << res << '\n';
    } else {
        cout << n << '\n';
    }
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
https://codeforces.com/problemset/problem/1644/E
*/
