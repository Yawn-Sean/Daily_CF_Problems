#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10];
vector<pii> ans;

int pos[MAXN + 10];

void swp(int x, int y) {
    ans.push_back(pii(x, y));
    int u = A[x], v = A[y];
    swap(A[x], A[y]);
    swap(pos[u], pos[v]);
}

void gao(int x) {
    if (pos[x] == x) return;

    if (pos[x] <= n / 2) swp(pos[x], n);
    else swp(pos[x], 1);

    int t = (x <= n / 2 ? n : 1);
    if (pos[x] != t) swp(pos[x], t);
    swp(pos[x], x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), pos[A[i]] = i;

    for (int i = 0; i < n / 2; i++) {
        gao(n / 2 - i);
        gao(n / 2 + i + 1);
    }

    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
