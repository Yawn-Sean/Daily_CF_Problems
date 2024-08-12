#include <bits/stdc++.h>
#define MAXA ((int) 1e5)
using namespace std;

vector<int> fac[MAXA + 10];
int vis[MAXA + 10];

int main() {
    for (int i = 1; i <= MAXA; i++) for (int j = i; j <= MAXA; j += i) fac[j].push_back(i);

    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        int ans = 0;
        for (int z : fac[x]) {
            if (vis[z] < i - y) ans++;
            vis[z] = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
