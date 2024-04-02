#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    while (cin >> n) {
        vector<pair<int, int>> a, b;
        for (i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x > y) {
                a.emplace_back(x, i + 1);
            } else {
                b.emplace_back(y, i + 1);
            }
        } 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<pair<int, int>>());
        if (a.size() < b.size()) {
            cout << b.size() << '\n';
            for (i = 0; i < b.size(); ++i) {
                cout << b[i].second << " \n"[i == b.size() - 1];
            }
        } else {
            cout << a.size() << '\n';
            for (i = 0; i < a.size(); ++i) {
                cout << a[i].second << " \n"[i == a.size() - 1];
            }
        }
    }
    return 0;
}