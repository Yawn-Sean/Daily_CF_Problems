#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n;
__int128 tree1[MAXN + 10], tree2[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(__int128 *tree, int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

__int128 query(__int128 *tree, int pos) {
    __int128 ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    long long m;
    scanf("%d%lld%*lld", &n, &m); n--;

    vector<array<long long, 3>> vec;
    for (int i = 1; i <= n; i++) {
        long long x, y; scanf("%lld%lld", &x, &y);
        vec.push_back({x, y - x + 1, 0});
    }
    sort(vec.begin(), vec.end(), [&](array<long long, 3> &arr1, array<long long, 3> &arr2) {
        return arr1[1] < arr2[1];
    });
    for (int i = 0; i < n; i++) vec[i][2] = i + 1;
    sort(vec.begin(), vec.end(), greater<array<long long, 3>>());
    vec.push_back({0, 0, 0});

    int ans = 1;
    for (int i = 0; i < n; i++) if (vec[i][0] > m) ans++;

    for (int i = 0; i < n; i++) {
        add(tree1, vec[i][2], vec[i][1]);
        add(tree2, vec[i][2], 1);
        if (vec[i][0] == 0) break;
        if (vec[i][0] == vec[i + 1][0]) continue;
        long long has = m - vec[i + 1][0];
        if (has < 0) continue;

        int head = 0, tail = n;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (query(tree1, mid) <= has) head = mid;
            else tail = mid - 1;
        }

        int cnt = query(tree2, head);
        ans = min(ans, i + 2 - cnt);
    }
    printf("%d\n", ans);
    return 0;
}
