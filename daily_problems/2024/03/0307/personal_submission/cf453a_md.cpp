#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    double m, n;
    cin >> m >> n;

    double acc = 0.0;
    for (int i = 1; i <= m; ++i) {
        acc += i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
    }

    cout << acc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}