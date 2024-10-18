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
    int n = red(), m = red(), res = INT_MAX;
    while (m--) {
        int l = red(), r = red();
        res = min(res, r - l + 1);
    }
    cout << res << '\n';
    int cur = 0;
    rep(i, 0, n) {
        cur %= res;
        cout << cur << " \n"[i == n - 1];
        cur++;
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
