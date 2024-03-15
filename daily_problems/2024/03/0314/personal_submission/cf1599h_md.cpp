#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int query(int i, int j) {
    int ret;
    cout << "? " << i << " " << j << endl;
    cin >> ret;
    return ret;
}

constexpr int c_bound = 1e9;

void solve() {
    int d1 = query(1, 1);
    int d2 = query(1, c_bound);
    int d3 = query(c_bound, 1);
    int mid = (d1 - d3 + c_bound + 1) / 2;
    int d4 = query(mid, 1);
    cout << "! " << (d1 + 1 - d4) << " " << (d4 + 1) << " "
         << (d4 - d3 + c_bound) << " " << (d1 - d2 - d4 + c_bound) << endl;
    return;
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