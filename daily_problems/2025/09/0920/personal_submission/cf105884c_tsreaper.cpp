#include <bits/stdc++.h>
#define MAXN 4000
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
bool flag[MAXN + 5];

int quad(int base, int idx) {
    int x = X[idx] - X[base], y = Y[idx] - Y[base];
    return (y < 0 ? 1 : 0) << 1 | (x < 0 ? 1 : 0) ^ (y < 0 ? 1 : 0);
}

long long cross(int base, int a, int b) {
    int xa = X[a] - X[base], ya = Y[a] - Y[base];
    int xb = X[b] - X[base], yb = Y[b] - Y[base];
    return 1LL * xa * yb - 1LL * xb * ya;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    int j = 1;
    for (int i = 2; i <= n; i++) if (Y[i] < Y[j] || (Y[i] == Y[j] && X[i] < X[j])) j = i;

    vector<int> ord;
    for (int i = 1; i <= n; i++) if (i != j) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        int qa = quad(j, a), qb = quad(j, b);
        if (qa != qb) return qa < qb;
        return cross(j, a, b) > 0;
    });

    for (int i = 1; i <= n; i++) flag[i] = false;
    vector<int> conv = {j, ord[0], ord[1]};
    for (int i = 2; i < ord.size(); i++) {
        while (conv.size() >= 3 && cross(conv[conv.size() - 2], conv.back(), ord[i]) < 0) {
            flag[conv.back()] = true;
            conv.pop_back();
        }
        conv.push_back(ord[i]);
    }

    for (int i = 1; i <= n; i++) if (flag[i]) {
        for (int k = 1, l = 2; l < conv.size(); k++, l++) {
            if (cross(i, j, conv[k]) > 0 && cross(i, conv[k], conv[l]) > 0 && cross(i, conv[l], j) > 0) {
                printf("%d %d %d %d\n", i, j, conv[k], conv[l]);
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
