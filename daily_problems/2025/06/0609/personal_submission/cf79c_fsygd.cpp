#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans, start;
int len[10], nxt[10][20], pointer[10];
char s[100010], b[10][20];

int main() {
    scanf("%s%d", s, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", b[i]);
        len[i] = strlen(b[i]);
        nxt[i][0] = -1;
        for (int j = 1; j < len[i]; ++j) {
            nxt[i][j] = nxt[i][j - 1];
            while (nxt[i][j] >= 0 && b[i][nxt[i][j] + 1] != b[i][j]) nxt[i][j] = nxt[i][nxt[i][j]];
            if (b[i][nxt[i][j] + 1] == b[i][j]) ++nxt[i][j];
        }
    }

    int pre = 0, L = strlen(s);
    for (int j = 0; j < n; ++j) pointer[j] = -1;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < n; ++j) {
            while (pointer[j] >= 0 && b[j][pointer[j] + 1] != s[i]) pointer[j] = nxt[j][pointer[j]];
            if (b[j][pointer[j] + 1] == s[i]) ++pointer[j];
            if (pointer[j] == len[j] - 1) {
                pre = max(pre, i - len[j] + 2);
                pointer[j] = nxt[j][pointer[j]];
            }
        }
        if (i - pre + 1 > ans) {
            ans = i - pre + 1;
            start = pre;
        }
    }
    printf("%d %d\n", ans, start);
    return 0;
}