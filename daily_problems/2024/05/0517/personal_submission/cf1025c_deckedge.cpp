#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define pb push_back
#define em emplace_back
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
    int n = s.size(), i;
    string t;
    t.resize(n * 2);
    rep(i, 0, n) {
        t[i] = s[i];
        t[i + n] = s[i];
    }
    int cnt = 1, res = 1;
    rep(i, 1, n * 2) {
        if (t[i] != t[i - 1]) {
            cnt++;
            res = max(res, cnt);
        } else {
            cnt = 1;
        }
    }
    cout << (res > n ? n : res) << '\n';
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

