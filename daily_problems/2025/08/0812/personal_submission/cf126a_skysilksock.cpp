#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    // 特判边界情况
    if (t0 == t1 && t0 == t2) {
        cout << x1 << " " << x2 << endl;
        return 0;
    } else if (t0 == t1) {
        cout << x1 << " " << 0 << endl;
        return 0;
    } else if (t0 == t2) {
        cout << 0 << " " << x2 << endl;
        return 0;
    }

    int y1 = 0, y2 = 0;
    int ans1 = x1, ans2 = x2;
    double cur = 1e18;

    while (ans1 >= 0 && ans2 >= 0) {
        if (ans1 == 0 && ans2 == 0) break;
        double t = (1.0 * ans1 * t1 + 1.0 * ans2 * t2) / (ans1 + ans2);
        if (t < t0) {
            ans1--;
        } else {
            if (t - t0 < cur) {
                cur = t - t0;
                y1 = ans1;
                y2 = ans2;
            }
            ans2--;
        }
    }

    cout << y1 << " " << y2 << endl;
    return 0;
}