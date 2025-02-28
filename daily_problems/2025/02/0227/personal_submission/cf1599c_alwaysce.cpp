#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    long double p;
    cin >> n >> p;
    for (int i = 0; i <= n; i++) {
        long double prob = 0.0;
        // 3张都看 c(3,x)
        prob += i * (i - 1) * (i - 2) / 6;
        // 2张看过 c(2,x)*c(1,n-x)
        prob += i * (i - 1) * (n - i) / 2;
        // 1张看过 c(1,x) * c(2,n-x)
        prob += (long double)1.0 / 2 * i * (n - i) * (n - i - 1) / 2;
        if (prob / (n * (n - 1) * (n - 2) / 6) >= p) {
            cout << i;
            break;
        }
    }
    return 0;
}
