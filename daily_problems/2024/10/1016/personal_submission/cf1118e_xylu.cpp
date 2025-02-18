#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int __FAST_IO__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solveE() {
    int n, k;
    cin >> n >> k;
    if (1LL * k * k - k < n) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    for (int i = 0, x = 1, y = 2; i < n; i++) {
        cout << x << " " << y << "\n";
        y--, x++;
        if (x == y) y--, x++;
        if (y == 0 || x == k + 1) {
            if (x + y < k) y = x + y, x = 1;
            else x = x + y + 1 - k, y = k;
        }
    }
}

int main() {
    solveE();
}
