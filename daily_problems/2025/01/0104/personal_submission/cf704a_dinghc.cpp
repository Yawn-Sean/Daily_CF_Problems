#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int ans = 0;
    vector<int> g;
    vector<int> cnt(n + 1, 0);
    vector<int> unr(n + 1, 0);
    int pos = 0;
    for (int i = 0, t, x; i < q; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            g.push_back(x);
            cnt[x] += 1;
            ans += 1;
        } else if (t == 2) {
            ans -= cnt[x];
            cnt[x] = 0;
            unr[x] = g.size();
        } else {
            while (pos < x) {
                if (unr[g[pos]] <= pos) {
                    ans -= 1;
                    cnt[g[pos]] -= 1;
                }
                pos += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

