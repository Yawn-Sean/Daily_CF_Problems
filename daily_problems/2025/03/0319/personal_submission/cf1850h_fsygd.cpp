#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int T, n, m;
int f[200010];
long long g[200010];
 
int get_father(int x) {
    if (f[x] != x) {
        int tmp = f[x];
        f[x] = get_father(f[x]);
        g[x] += g[tmp];
    }
    return f[x];
}
 
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            f[i] = i;
            g[i] = 0;
        }
        bool flag = true;
        for (int i = 1; i <= m; ++i) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            int fa = get_father(a);
            int fb = get_father(b);
            if (fa == fb) {
                if (g[a] != g[b] - d) flag = false;
            }
            else {
                f[fa] = fb;
                g[fa] = g[b] - g[a] - d;
            }
        }
        if (flag) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}