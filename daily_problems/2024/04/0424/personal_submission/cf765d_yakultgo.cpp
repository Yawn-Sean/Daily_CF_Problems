#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, g[maxn], h[maxn], tot;
int main() {
    cin >> n;
    for (int i(1); i <= n; ++i) {
        int x;
        cin >> x;
        if (!g[x])
            g[x] = ++tot, h[tot] = x, g[i] = tot;
        else if (h[g[x]] == x)
            g[i] = g[x];
        else {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << tot << endl;
    for (int i(1); i <= n; ++i) cout << g[i] << " ";
    cout << endl;
    for (int i(1); i <= tot; ++i) cout << h[i] << " ";
    return 0;
}