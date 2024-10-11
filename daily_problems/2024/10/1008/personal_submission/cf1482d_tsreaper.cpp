#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];
vector<int> ans;

int pre[MAXN + 10], nxt[MAXN + 10];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) {
        pre[i] = (i > 1 ? i - 1 : n);
        nxt[i] = (i < n ? i + 1 : 1);
    }

    ans.clear();
    list<int> lst;
    for (int i = 1; i <= n; i++) if (gcd(A[i], A[nxt[i]]) == 1) lst.push_back(nxt[i]);
    auto it = lst.begin();
    while (!lst.empty()) {
        if (it == lst.end()) it = lst.begin();
        int idx = *it;
        ans.push_back(idx);
        if (ans.size() == n) break;
        it = lst.erase(it);
        if (!lst.empty()) {
            if (it == lst.end()) it = lst.begin();
            if (pre[*it] == idx) it = lst.erase(it);
        }
        if (gcd(A[pre[idx]], A[nxt[idx]]) == 1) lst.insert(it, nxt[idx]);
        nxt[pre[idx]] = nxt[idx];
        pre[nxt[idx]] = pre[idx];
    }

    printf("%d", ans.size());
    for (int x : ans) printf(" %d", x);
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
