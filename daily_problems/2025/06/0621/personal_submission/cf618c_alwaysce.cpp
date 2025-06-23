#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<i64> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return xs[i] < xs[j] || (xs[i] == xs[j] && ys[i] < ys[j]);
    });


    i64 ax = xs[order[0]], ay = ys[order[0]];
    i64 bx = xs[order[1]], by = ys[order[1]];
    for (int i = 2; i < n; i++) {
        i64 cx = xs[order[i]], cy = ys[order[i]];
        // Check if the points are collinear
        if ((bx - ax) * (cy - ay) != (by - ay) * (cx - ax)) {
            cout << order[0] + 1 << ' ' << order[1] + 1 << ' ' << order[i] + 1 << endl;
            return 0;
        }
    }
    return 0;
}
