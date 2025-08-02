#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q;

vector<int> fac[MAXN + 5];
bool vis[MAXN + 5];
int now[MAXN + 5];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) if (fac[i].empty()) for (int j = i; j <= n; j += i) fac[j].push_back(i);
    while (q--) {
        char op[3]; int x; scanf("%s%d", op, &x);
        if (op[0] == '+') {
            if (vis[x]) printf("Already on\n");
            else {
                bool ok = true;
                for (int y : fac[x]) if (now[y]) {
                    printf("Conflict with %d\n", now[y]);
                    ok = false;
                    break;
                }
                if (ok) {
                    vis[x] = true;
                    for (int y : fac[x]) now[y] = x;
                    printf("Success\n");
                }
            }
        } else {
            if (!vis[x]) printf("Already off\n");
            else {
                vis[x] = false;
                for (int y : fac[x]) now[y] = 0;
                printf("Success\n");
            }
        }
    }
    return 0;
}
