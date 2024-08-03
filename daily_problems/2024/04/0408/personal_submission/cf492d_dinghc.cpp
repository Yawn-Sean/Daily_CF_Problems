#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x, y;
    cin >> n >> x >> y;

    long long lcm = x * y / gcd(x, y);
    x = lcm / x;
    y = lcm / y;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (x == y) {
            cout << "Both\n";
        } else {
            long long num = *ranges::partition_point(views::iota(min(x, y), LONG_LONG_MAX), 
                [&] (long long m) {
                    return m / x + m / y < a;
                }
            );
            if (num % x == 0 && num % y == 0) {
                cout << "Both\n";
            } else if (num % x == 0) {
                cout << "Vanya\n";
            } else if (num % y == 0) {
                cout << "Vova\n";
            }
        }
    }

    return 0;
}

