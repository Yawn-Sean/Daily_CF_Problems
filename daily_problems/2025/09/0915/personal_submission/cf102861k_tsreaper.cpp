#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;

vector<int> e[MAXN + 5];
bitset<MAXN + 5> bs[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) { printf("N\n"); return 0; }
        if (e[i].size() & 1) {
            bs[i][i] = 1;
            for (int j : e[i]) bs[i][j] = 1;
        } else {
            for (int j : e[i]) bs[i][j] = 1;
            bs[i][n + 1] = 1;
        }
    }

    for (int r = 1, c = 1; c <= n; c++) {
        int key;
        for (key = r; key <= n; key++) if (bs[key][c]) break;
        if (key > n) continue;
        swap(bs[key], bs[r]);
        for (int rr = 1; rr <= n; rr++) if (r != rr && bs[rr][c]) bs[rr] ^= bs[r];
        r++;
    }

    for (int i = 1; i <= n; i++) {
        bool zero = true;
        for (int j = 1; j <= n; j++) if (bs[i][j]) { zero = false; break; }
        if (zero && bs[i][n + 1]) { printf("N\n"); return 0; }
    }
    printf("Y\n"); return 0;
}
