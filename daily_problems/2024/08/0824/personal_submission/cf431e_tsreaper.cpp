#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXQ ((int) 1e5)
#define TRIES 50
using namespace std;

int n, m, q, H[MAXN + 10];
long long QRY[MAXQ + 10][3];

map<int, int> mp;
vector<int> nums;
long long tree[2][MAXN + MAXQ + 10];

int lb(int x) { return x & (-x); }

void add(long long *tree, int pos, long long val) {
    for (; pos <= m; pos += lb(pos)) tree[pos] += val;
}

long long query(long long *tree, int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int idx(double val) {
    if (val < nums[0]) return 0;
    int head = 1, tail = m;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (nums[mid - 1] <= val) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &H[i]), mp[H[i]] = 1;
    for (int i = 1; i <= q; i++) {
        scanf("%lld", &QRY[i][0]);
        if (QRY[i][0] == 1) scanf("%lld%lld", &QRY[i][1], &QRY[i][2]), mp[QRY[i][2]] = 1;
        else scanf("%lld", &QRY[i][1]);
    }

    for (auto &p : mp) nums.push_back(p.first), p.second = ++m;
    for (int i = 1; i <= n; i++) {
        add(tree[0], idx(H[i]), 1);
        add(tree[1], idx(H[i]), H[i]);
    }
    for (int i = 1; i <= q; i++) {
        if (QRY[i][0] == 1) {
            int pos = QRY[i][1];
            add(tree[0], idx(H[pos]), -1);
            add(tree[1], idx(H[pos]), -H[pos]);
            H[pos] = QRY[i][2];
            add(tree[0], idx(H[pos]), 1);
            add(tree[1], idx(H[pos]), H[pos]);
        } else {
            double head = 0, tail = 2e10;
            for (int t = 1; t <= TRIES; t++) {
                double mid = (head + tail) / 2;
                int pos = idx(mid);
                if (query(tree[0], pos) * mid - query(tree[1], pos) >= QRY[i][1]) tail = mid;
                else head = mid;
            }
            printf("%.6f\n", (head + tail) / 2);
        }
    }
    return 0;
}
