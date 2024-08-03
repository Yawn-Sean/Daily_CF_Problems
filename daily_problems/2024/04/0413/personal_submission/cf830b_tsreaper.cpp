#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, tree[MAXN + 10];
long long ans;

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
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) add(i, 1);
    int now = 0;
    for (auto &p : mp) {
        auto &vec = p.second;
        auto it = upper_bound(vec.begin(), vec.end(), now);
        if (it == vec.end()) it = vec.begin();
        int idx = it - vec.begin();
        for (int i = 0; i < vec.size(); i++) {
            int pos = vec[(idx + i) % vec.size()];
            if (pos < now) {
                ans += query(n) - query(now);
                ans += query(pos);
            } else {
                ans += query(pos) - query(now);
            }
            add(pos, -1);
            now = pos;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
