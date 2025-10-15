#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 18
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &A[i]);

    for (int p = MAXP; p >= 0; p--) {
        vector<int> group[2];
        int now = 0;
        group[0].push_back(1);
        for (int i = 2; i <= n; i++) {
            now ^= A[i - 1] >> p & 1;
            group[now].push_back(i);
        }

        int flag = group[0].size() < group[1].size() ? 1 : 0;
        for (int k = 0; k < 2; k++) for (int x : group[k]) ans[x] |= (k ^ flag) << p;
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
