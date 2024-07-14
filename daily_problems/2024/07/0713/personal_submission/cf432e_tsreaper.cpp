#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef pair<int, int> pii;

int n, m;

char ans[MAXN + 10][MAXN + 10];
pii f[MAXN + 10][MAXN + 10];

void gao(int SI, int SJ) {
    for (int c = 0; c < 26; c++) {
        if (ans[SI - 1][SJ] == c + 'A') continue;
        if (ans[SI][SJ + 1] == c + 'A') continue;
        if (ans[SI][SJ - 1] == c + 'A') {
            int i = f[SI][SJ - 1].first, j = f[SI][SJ - 1].second;
            if (i != SI) continue;
            int len = SJ - j;
            if (i + len > n) continue;
            for (int ii = i; ii <= i + len; ii++) f[ii][SJ] = {i, j}, ans[ii][SJ] = c + 'A';
            for (int jj = j; jj <= j + len; jj++) f[i + len][jj] = {i, j}, ans[i + len][jj] = c + 'A';
            return;
        }
        f[SI][SJ] = {SI, SJ}; ans[SI][SJ] = c + 'A';
        return;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (!ans[i][j]) gao(i, j);
    for (int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
    return 0;
}
