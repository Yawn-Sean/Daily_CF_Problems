#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int64 x, y, p, q;
        cin >> x >> y >> p >> q;

        if (p == 1 && q == 1) {
            if (x == y) {
                cout << "0";
            } else {
                cout << "-1";
            }
        } else {
            if (p == 0) {
                if (x == 0) {
                    cout << "0";
                } else {
                    cout << "-1";
                }
            } else {
                // m is minimum
                // x <= m*p and m*p <= x + (m*q - y)
                int64 m = max(((y - x) + (q - p) - 1) / (q - p), (x + p - 1) / p);
                cout << m * q - y;
            }
        }
    
        cout << "\n";
    }
    return 0;
}

