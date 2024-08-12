#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 10];
long long ans;

int tree[MAXN + 10];

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
    scanf("%d", &n);
    vector<array<int, 3>> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        vec.push_back({-A[i], -1, i});
        vec.push_back({-i, 1, min(i - 1, A[i])});
    }
    sort(vec.begin(), vec.end());

    for (auto &arr : vec) {
        if (arr[1] < 0) add(arr[2], 1);
        else ans += query(arr[2]);
    }
    printf("%lld\n", ans);
    return 0;
}
