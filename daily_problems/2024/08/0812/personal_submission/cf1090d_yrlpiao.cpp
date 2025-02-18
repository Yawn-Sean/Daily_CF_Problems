#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int a[N], b[N], n, m;
set<int> s[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        s[min(u, v)].insert(max(u, v));
    }
    for (int i = 1; i <= n; i++) a[i] = b[i] = i;
    for (int i = 1; i < n; i++) {
        if (s[i].size() == n - i) continue;
        for (int j = i + 1; j <= n; j++) {
            if (s[i].count(j)) continue;
            swap(a[i + 1], a[j]);
            swap(b[i + 1], b[j]);
            b[j] = i;
            puts("YES");
            for (int k = 1; k <= n; k++) cout << a[k] << " \n"[k == n];
            for (int k = 1; k <= n; k++) cout << b[k] << " ";
            return 0;
        }
    }
    puts("NO");
    return 0;
}
