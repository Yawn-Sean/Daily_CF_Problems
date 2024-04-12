#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    const int p = 100003;
    cout << p << " " << p << endl;
    cout << 1 << " " << 2 << " " << p - (n - 2) << endl;
    for (int i = 2; i <= n - 1; ++i) {
        cout << i << " " << i + 1 << " " << 1 << endl;
    }

    int cnt = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            if (cnt++ <= m) {
                cout << i << " " << j << " " << static_cast<int>(1e9) << endl;
            } else {
                return 0;
            }
        }
    }

    return 0;
}