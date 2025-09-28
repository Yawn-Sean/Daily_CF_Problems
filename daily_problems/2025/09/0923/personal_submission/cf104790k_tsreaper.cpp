#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, int>> mp;
int bi = -1, bj = -1, bv = -1;

int query(int i, int j) {
    int v = mp[i][j];
    if (v > 0) return v;
    printf("? %d %d\n", i, j); fflush(stdout);
    scanf("%d", &v);
    if (v > bv) bi = i, bj = j, bv = v;
    return mp[i][j] = v;
}

int main() {
    int n; scanf("%d", &n);

    int u = 1, d = n, l = 1, r = n;
    while (u < d || l < r) {
        int midi = (u + d) / 2, midj = (l + r) / 2;
        for (int j = l; j <= r; j++) query(midi, j);
        for (int i = u; i <= d; i++) query(i, midj);

        if (bi == midi) {
            if (bi > 1) query(bi - 1, bj);
            if (bi < n) query(bi + 1, bj);
        }
        if (bj == midj) {
            if (bj > 1) query(bi, bj - 1);
            if (bj < n) query(bi, bj + 1);
        }

        if (bi == midi || bj == midj) u = d = bi, l = r = bj;
        else {
            if (bi < midi) d = midi - 1;
            else u = midi + 1;
            if (bj < midj) r = midj - 1;
            else l = midj + 1;
        }
    }

    printf("! %d\n", query(u, l)); fflush(stdout);
    return 0;
}
