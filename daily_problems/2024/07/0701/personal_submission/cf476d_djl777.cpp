#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int a[4] = {1, 2, 3, 5};
    cout << k * (6 * n - 1) << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cout << (6 * i + a[j]) * k << ' ';
        cout << '\n';
    }

    return 0;
}