#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    bool one_line = (x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3);
    if (one_line) {
        cout << 1 << endl;
        return 0;
    }

    bool check12 = [&]() {
        // 1 2/ 2 3 / 1 3
        if (x1 == x2) {
            return min(y1, y2) >= y3 || y3 >= max(y1, y2);
        }
        if (y1 == y2) {
            return min(x1, x2) >= x3 || x3 >= max(x1, x2);
        }
        return false;
    }();

    bool check23 = [&]() {
        if (x2 == x3) {
            return min(y2, y3) >= y1 || y1 >= max(y2, y3);
        }
        if (y2 == y3) {
            return min(x2, x3) >= x1 || x1 >= max(x2, x3);
        }
        return false;
    }();

    bool check13 = [&]() {
        if (x1 == x3) {
            return min(y1, y3) >= y2 || y2 >= max(y1, y3);
        }
        if (y1 == y3) {
            return min(x1, x3) >= x2 || x2 >= max(x1, x3);
        }
        return false;
    }();

    if (check12 || check23 || check13) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}
