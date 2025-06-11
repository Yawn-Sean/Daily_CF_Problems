#include <bits/stdc++.h>
#define MAXM ((int) 1e7)
using namespace std;

bool vis[MAXM + 10];

int main() {
    int a, b, m; scanf("%d%d%d", &a, &b, &m);
    for (int i = 0; i <= a; i++) {
        int t = 1LL * i * ((int) 1e9) % m;
        if (vis[t]) break;
        vis[t] = true;
        if (t > 0 && t + b < m) { printf("1 %09d\n", i); return 0; }
    }
    printf("2\n");
    return 0;
}
