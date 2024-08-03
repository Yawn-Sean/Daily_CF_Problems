#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int x = *ranges::partition_point(views::iota(1LL, LONG_LONG_MAX), [&] (long long x) {
        return (1 + x) * x / 2 <= a + b;
    }) - 1;

    int n = 0;
    vector<bool> d(x + 1, false);
    for (int i = x; i > 0 && a > 0; i--, n++) {
        int mn = min(i, a);
        d[mn] = true;
        a -= mn;
    }

    cout << n << "\n";
    for (int i = 1; i <= x; i++) {
        if (d[i]) cout << i << " ";
    }
    cout << "\n" << x - n << "\n";
    for (int i = 1; i <= x; i++) {
        if (!d[i]) cout << i << " ";
    }

    return 0;
}

