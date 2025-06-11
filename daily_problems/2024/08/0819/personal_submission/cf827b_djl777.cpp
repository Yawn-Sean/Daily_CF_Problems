#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << (n - 1) / k * 2 + min(2, (n - 1) % k) << '\n';
    for (int i = 1; i <= k; i++)
        cout << n << ' ' << i << '\n';
    for (int i = k + 1; i < n; i++)
        cout << i << ' ' << i - k << '\n';

    return 0;
}