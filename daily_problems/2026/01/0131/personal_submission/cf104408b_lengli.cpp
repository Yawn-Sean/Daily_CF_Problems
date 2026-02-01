#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout.setf(std::ios::fixed);
    cout << setprecision(10);

    for(int _ = 0; _ < t; ++_) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        double ans;
        if (x1 == 0 && x2 == 0) {
            ans = fabs(y1 - y2);
        } else if (y1 == 0 && y2 == 0) {
            ans = fabs(x1 - x2);
        } else {
            double v1 = fabs(x1) + fabs(y1);
            double v2 = fabs(x2) + fabs(y2);

            if (v1 > v2) swap(v1, v2);

            ans = 3.14159265358 / 2.0 * v1 + (v2 - v1);
        }

        cout << ans << "\n";
    }

    return 0;
}
