#include <iostream>
#include <numeric>
using namespace std;

const int N = 1 << 18;

int to[N] {}, fa[N] {}, ifa[N] {}, n;

int find(int fa[], int u) {
    if (fa[u] == u) return u;
    return fa[u] = find(fa, fa[u]);
}

void yrlpSolve() {
    cin >> n;
    long long r = 1LL * n * (n + 1) / 2;
    iota(fa, fa + n + 1, 0);
    iota(ifa, ifa + n + 1, 0);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        int uu = find(fa, u), vv = find(ifa, v);
        to[uu] = vv;
        fa[uu] = vv, ifa[vv] = uu;
        r -= vv;
    }
    while (r != 0) {
        cout << r << " ";
        r = to[r];
    }
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
