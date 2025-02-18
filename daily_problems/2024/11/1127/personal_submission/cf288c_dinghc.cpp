#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    int q = n;
    while (q > 0) {
        int k = 1 << (32 - __builtin_clz(q) - 1);
        int nq = k - 1;
        for (int i = k; i <= q; i++, nq--) {
            p[i] = nq;
            p[nq] = i;
        }
        q = nq;
    }
    cout << 1LL * n * (n + 1) << "\n";
    for (int i = 0; i <= n; i++) {
        cout << p[i] << " ";
    }
    return 0;
}

