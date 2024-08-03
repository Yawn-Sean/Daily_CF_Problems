#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 2>> p(n, array<int, 2>());
    for (auto& [a1, a2] : p) {
        cin >> a1 >> a2;
        a1--;
        a2--;
    }
    if (n == 3) {
        cout << "1 2 3" << "\n";
    } else {
        int x = p[0][0], y = p[0][1];
        if (p[x][0] != y && p[x][1] != y) {
            swap(x, y);
        }
        cout << "1 " << x + 1 << " " << y + 1 << " ";
        for (int i = 3; i < n; i++) {
            auto& [x1, x2] = p[x];
            if (x1 == y) {
                cout << x2 + 1 << " ";
                x = x1;
                y = x2;
            } else {
                cout << x1 + 1 << " ";
                x = x2;
                y = x1;
            }
        }
        cout << "\n";
    }
    return 0;
}

