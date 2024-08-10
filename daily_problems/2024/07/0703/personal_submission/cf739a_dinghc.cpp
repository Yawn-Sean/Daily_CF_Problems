#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int mn = n;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        mn = min(mn, y - x + 1);
    }
    cout << mn << "\n";
    for (int i = 0; i < n; i++) {
        cout << i % mn << " ";
    }
    cout << "\n";
    return 0;
}

