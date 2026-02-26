#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        cout << 1 << "\n";
    }
    else if (n == 2) {
        cout << -1 << "\n";
    }
    else {
        // 3 << (n - 2)
        cout << (3LL << (n - 2)) << "\n";

        cout << 1 << " " << 2;

        for (ll i = 0; i < n - 2; i++) {
            cout << " " << (3LL << i);
        }

        cout << "\n";
    }

    return 0;
}
