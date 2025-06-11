#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define int long long 
int inf = 0x3f3f3f3f;
int w[30][30] {};

void yrlpSolve() {
    string a, b; cin >> a >> b;
    int n; cin >> n;
    memset(w, 0x3f, sizeof w);
    for (int i = 0; i < 26; i++) w[i][i] = 0;
    for (int i = 0; i < n; i++) {
        char u, v; cin >> u >> v;
        int x; cin >> x;
        int p = u - 'a', l = v - 'a';
        w[p][l] = min(w[p][l], x);
    }
    if (a.size() != b.size()) {
        cout << -1 << endl;
        return;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        int u = a[i] - 'a', v = b[i] - 'a';
        int ret = inf;
        for (int j = 0; j < 26; j++) {
            if (w[u][j] + w[v][j] < ret) {
                ret = w[u][j] + w[v][j];
                a[i] = j + 'a';
                b[i] = j + 'a';
            }
        }
        ans += ret;
    }
    if (ans >= inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        cout << a << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
