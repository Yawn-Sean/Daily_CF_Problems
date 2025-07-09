#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, A[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    unordered_set<int> st[2];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        st[A[i] & 1].insert(A[i]);
    }

    for (int i = 0; i < 2; i++) {
        int now = i ? 1 : 2;
        while (st[i].size() < n / 2) {
            while (st[i].count(now) && now <= m) now += 2;
            if (now > m) { printf("-1\n"); return 0; }
            st[i].insert(now);
        }
    }

    unordered_set<int> fin;
    for (int i = 0; i < 2; i++) {
        auto it = st[i].begin();
        for (int j = 1; j <= n / 2; j++) fin.insert(*it), it++;
    }

    for (int i = 1; i <= n; i++) if (fin.count(A[i])) ans[i] = A[i], fin.erase(A[i]);
    printf("%d\n", fin.size());
    for (int i = 1; i <= n; i++) if (ans[i] == 0) ans[i] = *fin.begin(), fin.erase(fin.begin());
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
