#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, b;
    cin >> r >> b;
    vector<int> x(r), y(r);
    for (int i = 0; i < r; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> bx(b), by(b);
    for (int i = 0; i < b; i++) {
        cin >> bx[i] >> by[i];
    }

    if (r == b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
