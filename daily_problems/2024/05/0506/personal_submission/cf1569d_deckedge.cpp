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
    int n = red(), m = red(), k = red(), i, j;
    map<pi, int> mpy, mpx;
    vector<int> x(n), y(m), mx(n), my(m);
    generate(all(x), red);
    generate(all(y), red);
    int64_t res = 0;
    while (k--) {
        int u = red(), v = red();
        int cx = lower_bound(x.begin(), x.end(), u) - x.begin();
        int cy = lower_bound(y.begin(), y.end(), v) - y.begin();
        if (u == x[cx]) {
            if (v == y[cy]) {
                continue;
            }
            res += my[cy]++ - mpx[{cy, cx}]++; 
        } else {
            res += mx[cx]++ - mpy[{cx, cy}]++;
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

