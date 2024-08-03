#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    vector<int> f(n+1);
    unordered_map<int, int> same;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == f[i]) same[i] = ++m;
        else if (f[f[i]] != f[i]) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> g(n+1, 0), h(m+1, 0);
    cout << m << '\n';
    for (int i = 1; i <= n; i++) {
        g[i] = same[f[i]];
        if (i == f[i]) {
            h[same[i]] = i;
        }
        cout << g[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= m; i++) {
        cout << h[i] << ' ';
    }
    cout << '\n';
    return 0;
}
