#include <bits/stdc++.h>
#define MAXQ ((int) 1e5)
using namespace std;

int n, q, QRY[MAXQ + 10][3], ans[MAXQ + 10];
int tree[MAXQ + 10];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &q);

    map<int, int> mp;
    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &QRY[i][j]);
        mp[QRY[i][1]] = 1;
    }
    for (auto &p : mp) p.second = ++n;
    for (int i = 1; i <= q; i++) QRY[i][1] = mp[QRY[i][1]];

    unordered_map<int, vector<int>> groups;
    for (int i = 1; i <= q; i++) groups[QRY[i][2]].push_back(i);
    for (auto &p : groups) {
        for (int idx : p.second) {
            if (QRY[idx][0] == 1) add(QRY[idx][1], 1);
            else if (QRY[idx][0] == 2) add(QRY[idx][1], -1);
            else ans[idx] = query(QRY[idx][1]);
        }
        for (int idx : p.second) {
            if (QRY[idx][0] == 1) add(QRY[idx][1], -1);
            else if (QRY[idx][0] == 2) add(QRY[idx][1], 1);
        }
    }

    for (int i = 1; i <= q; i++) if (QRY[i][0] == 3) printf("%d\n", ans[i]);
    return 0;
}
