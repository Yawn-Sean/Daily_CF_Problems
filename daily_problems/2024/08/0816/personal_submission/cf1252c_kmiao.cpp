#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;

    vi R(n), C(n), pr(n+1), pc(n+1);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
        R[i] %= 2;
        pr[i + 1] = pr[i] + R[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        C[i] %= 2;
        pc[i + 1] = pc[i] + C[i];
    }
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = pr[max(r1, r2)] - pr[min(r1, r2) - 1] + pc[max(c1, c2)] - pc[min(c1, c2) - 1];
        if (sum == 0 || sum == abs(r1 - r2) + abs(c1 - c2) + 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
