#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5], B[MAXN + 5];
vector<pii> ans;

unordered_map<int, unordered_set<int>> pos;

bool check(int x) {
    for (; x; x /= 10) if (x % 10 != 4 && x % 10 != 7) return false;
    return true;
}

void swp(int x, int y) {
    if (x == y) return;
    ans.push_back({x, y});
    pos[A[x]].erase(x);
    pos[A[y]].erase(y);
    swap(A[x], A[y]);
    pos[A[x]].insert(x);
    pos[A[y]].insert(y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
        pos[A[i]].insert(i);
    }
    sort(B + 1, B + n + 1);

    int key = 0;
    for (int i = 1; i <= n; i++) if (check(A[i])) { key = A[i]; break; }
    if (key == 0) {
        for (int i = 1; i <= n; i++) if (A[i] != B[i]) { printf("-1\n"); return 0; }
        printf("0\n"); return 0;
    }

    for (int i = 1; i <= n; i++) if (B[i] != key) {
        if (A[i] != B[i]) {
            swp(i, *(pos[key].begin()));
            swp(i, *(pos[B[i]].begin()));
        }
        pos[A[i]].erase(i);
    }

    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
