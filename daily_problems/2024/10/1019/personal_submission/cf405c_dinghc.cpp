#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1'000;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < n; j++) {
            cin >> x;
            if (i == j) a[i] = x;
        }
        p ^= a[i];
    }
    int q;
    cin >> q;
    for (int i = 0, t, k; i < q; i++) {
        cin >> t;
        if (t == 3) {
            cout << p;
        } else {
            cin >> k;
            p ^= 1;
        }
    }
    return 0;
}

