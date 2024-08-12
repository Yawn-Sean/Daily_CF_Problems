#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read(), m = read(), cnt = 0;
    string s;
    cin >> s;
    rep(i, 1, n) {
        if (s[i] == s[i - 1] && s[i] == '.') {
            cnt++;
        }
    }
    
    auto add = [&](int idx, int p) {
        if (s[idx + 1] == '.') {
            cnt -= p;
        } 
        if (s[idx - 1] == '.') {
            cnt -= p;
        }
    };
    while (m--) {
        int a = read();
        char b;
        cin >> b;
        if (s[a - 1] == '.') {
            if (b != '.') {
                add(a - 1, 1);
            }
        } else {
            if (b == '.') {
                add(a - 1, -1);
            }
        }
        s[a - 1] = b;
        cout << cnt << '\n';
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