#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n;
char OP[MAXN + 10][5];

int f[MAXN + 10], ch[MAXN + 10][2];
bool flag[MAXN + 10];

int calc(int i, int x, int y) {
    if (OP[i][0] == 'A') return x & y;
    else if (OP[i][0] == 'O') return x | y;
    else return x ^ y;
}

int dfs1(int sn) {
    if (OP[sn][0] == 'I') return f[sn];
    else if (OP[sn][0] == 'N') return f[sn] = 1 - dfs1(ch[sn][0]);
    else return f[sn] = calc(sn, dfs1(ch[sn][0]), dfs1(ch[sn][1]));
}

void dfs2(int sn) {
    flag[sn] = true;
    if (OP[sn][0] == 'I') return;
    else if (OP[sn][0] == 'N') dfs2(ch[sn][0]);
    else {
        int x = ch[sn][0], y = ch[sn][1];
        if (calc(sn, f[x], f[y]) != calc(sn, 1 - f[x], f[y])) dfs2(x);
        if (calc(sn, f[x], f[y]) != calc(sn, f[x], 1 - f[y])) dfs2(y);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", OP[i]);
        if (OP[i][0] == 'I') scanf("%d", &f[i]);
        else if (OP[i][0] == 'N') scanf("%d", &ch[i][0]);
        else scanf("%d%d", &ch[i][0], &ch[i][1]);
    }

    dfs1(1); dfs2(1);
    for (int i = 1; i <= n; i++) if (OP[i][0] == 'I') {
        if (flag[i]) printf("%d", 1 - f[1]);
        else printf("%d", f[1]);
    }
    printf("\n");
    return 0;
}
