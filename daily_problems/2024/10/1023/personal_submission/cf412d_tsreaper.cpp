#include <bits/stdc++.h>
#define MAXN ((int) 3e4)
using namespace std;

int n, m, ans[MAXN + 10];
unordered_set<int> st[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        st[x].insert(y);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
        for (int j = i - 1; j > 0; j--) {
            if (st[ans[j]].count(i)) swap(ans[j], ans[j + 1]);
            else break;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
