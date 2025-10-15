#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
long long l;
int opt[100010][3];
int a[100010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &opt[i][0]);
        if (opt[i][0] == 1) scanf("%d", &opt[i][1]); else scanf("%d%d", &opt[i][1], &opt[i][2]);
    }
    n = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        long long x;
        scanf("%I64d", &x);
        while (x > l) {
            ++n;
            if (opt[n][0] == 1) {
                ++l;
                if (l <= 100000) a[l] = opt[n][1];
            }
            else {
                long long tmp = l + (long long)opt[n][1] * opt[n][2];
                for (int j = 1; j <= opt[n][2]; ++j) {
                    if (l >= 100000) break;
                    for (int k = 1; k <= opt[n][1]; ++k) {
                        if (l >= 100000) break;
                        a[++l] = a[k];
                    }
                }
                l = tmp;
            }
        }
        if (i > 1) printf(" ");
        if (opt[n][0] == 1) printf("%d", opt[n][1]); else printf("%d", a[(x - l + (long long)opt[n][1] * opt[n][2] - 1) % opt[n][1] + 1]);
    }
    printf("\n");
    return 0;
}