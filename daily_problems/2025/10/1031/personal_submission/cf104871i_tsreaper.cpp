#include <bits/stdc++.h>
#define MAXN ((int) 3e4)
#define MAXP 15
using namespace std;

int n;

int A[MAXP][MAXN + 5], deg[MAXN + 5];
long long f[MAXN + 5];
vector<int> e[MAXN + 5];

int main() {
    scanf("%d", &n);

    printf("QUERY ");
    for (int i = 1; i <= n; i++) printf("1");
    printf("\n"); fflush(stdout);
    for (int i = 1; i <= n; i++) scanf("%d", &deg[i]);

    for (int p = 0; p <= __lg(n); p++) {
        printf("QUERY ");
        for (int i = 1; i <= n; i++) printf("%d", i >> p & 1);
        printf("\n"); fflush(stdout);
        for (int i = 1; i <= n; i++) scanf("%d", &A[p][i]);
    }

    while (true) {
        bool done = true;
        for (int i = 1; i <= n; i++) if (deg[i] == 1) {
            long long sm = 0;
            for (int p = 0; p <= __lg(n); p++) sm += A[p][i] << p;
            int t = sm - f[i];
            deg[i] = 0; deg[t]--;
            e[i].push_back(t); f[t] += i;
            done = false;
        }
        if (done) break;
    }

    printf("ANSWER\n");
    for (int sn = 1; sn <= n; sn++) for (int fn : e[sn]) printf("%d %d\n", sn, fn);
    fflush(stdout);
    return 0;
}
