#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int N = 200'000;
pair<int, int> ops[N];

constexpr li MOD = 998'244'353LL;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k, q;
        scanf("%d%d%d%d", &n, &m, &k, &q);
        for (int i = 0, x, y; i < q; i++) {
            scanf("%d%d", &x, &y);
            ops[i] = make_pair(x, y);
        }
        li ans = 1LL;
        set<pair<int, int>> st;
        set<int> rs, cs;
        for (int i = q - 1; i >= 0 && rs.size() < n && cs.size() < m; i--) {
            auto& [x, y] = ops[i];
            bool flag = false;
            if (rs.find(x) == rs.end()) {
                rs.insert(x);
                flag = true;
            }
            if (cs.find(y) == cs.end()) {
                cs.insert(y);
                flag = true;
            }
            if (flag) {
                ans = (ans * k) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

