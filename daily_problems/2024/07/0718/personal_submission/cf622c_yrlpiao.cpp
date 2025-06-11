#include <iostream>
using namespace std;
const int N = 2e5 + 10;

int a[N], n, m, ne[N];

void yrlpSolve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), ne[i] = i + 1;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] == a[i + 1]) ne[i] = ne[i + 1];
    }
    while (m--) {
        int l, r, x, ans = -1; scanf("%d%d%d", &l, &r, &x);
        if (x != a[l]) ans = l;
        else if (ne[l] <= r) ans = ne[l];
        cout << ans << endl;
    }
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
