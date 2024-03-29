#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

/* https://codeforces.com/problemset/submission/891/253569177 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = a[0];
    for (int i = 1; g != 1 && i < n; i++) g = gcd(g, a[i]);

    if (g != 1) {
        cout << "-1\n";
    } else {
        int k = n;
        for (int i = 0; i < n && k; i++) {
            int g1 = a[i];
            int k1 = 0;
            for (int h = i + 1; g1 != 1 && h < n; h++) {
                g1 = gcd(g1, a[h]);
                ++k1;
            }
            if (g1 == 1) {
                k = min(k, k1);
            }
        }

        if (k == 0) {
            cout << count_if(a.begin(), a.end(), [] (int x) { return x != 1; }) << "\n";
        } else {
            cout << k + n - 1 << "\n";
        }
    }

    return 0;
}

