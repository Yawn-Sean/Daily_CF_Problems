#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];
long long ans;

int tree[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n + 1; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_map<long long, vector<pii>> mp;
    mp[0].push_back({0, 0});
    long long x = 0;
    int y = 0;
    for (int i = 1; i <= n; i++) {
        x += A[i];
        if (A[i] > 0) y--;
        else y++;
        mp[x].push_back({y, i});
    }

    for (auto &entry : mp) {
        auto &vec = entry.second;
        sort(vec.begin(), vec.end());
        for (pii p : vec) {
            ans += query(p.second + 1);
            add(p.second + 1, 1);
        }
        for (pii p : vec) add(p.second + 1, -1);
    }
    printf("%lld\n", ans);
    return 0;
}
