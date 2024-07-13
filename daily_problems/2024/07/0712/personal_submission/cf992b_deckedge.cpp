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
    int l = read(), r = read(), x = read(), y = read();
    if (y % x) {
        cout << 0;
        return ;
    }
    y /= x;
    int res = 0;
    for (int i = 1; i * i <= y; i++) {
        if ( y % i == 0 and gcd(i, y / i) == 1 and l <= x * i and x * i <= r and l <= y / i * x and y / i * x <= r) {
            res++;
            if (i != y / i) {
                res++;
            }
        }
    }
    cout << res;
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