#include <bits/stdc++.h>
using namespace std;

char s[30], ans[2][20];
int last[30];

void gao(int l, int r) {
    if (l + 1 == r) { printf("Impossible\n"); return; }
    if ((r - l) & 1) {
        int len = (r - l) / 2;
        for (int i = 1; i <= len; i++) ans[0][13 - (len - i)] = s[l + i];
        for (int i = 1; i <= len; i++) ans[1][14 - i] = s[l + len + i];
        ans[0][13 - len] = s[l];
        for (int i = l - 1, x = 0, y = 13 - len - 1; i > 0; i--) {
            if (y <= 0) x = 1, y = 1;
            ans[x][y] = s[i];
            if (x == 0) y--;
            else y++;
        }
        for (int i = r + 1, x = 1, y = 13 - len; i <= 27; i++) {
            if (y <= 0) x = 0, y = 1;
            ans[x][y] = s[i];
            if (x == 0) y++;
            else y--;
        }
    } else {
        int len = (r - l) / 2;
        for (int i = 1; i < len; i++) ans[0][13 - (len - 1 - i)] = s[l + i];
        for (int i = 1; i <= len; i++) ans[1][14 - i] = s[l + len - 1 + i];
        ans[0][14 - len] = s[l];
        for (int i = l - 1, x = 0, y = 13 - len; i > 0; i--) {
            if (y <= 0) x = 1, y = 1;
            ans[x][y] = s[i];
            if (x == 0) y--;
            else y++;
        }
        for (int i = r + 1, x = 1, y = 13 - len; i <= 27; i++) {
            if (y <= 0) x = 0, y = 1;
            ans[x][y] = s[i];
            if (x == 0) y++;
            else y--;
        }
    }
    printf("%s\n%s\n", ans[0] + 1, ans[1] + 1);
}

int main() {
    scanf("%s", s + 1);
    for (int i = 1; i <= 27; i++) {
        int c = s[i] - 'A';
        if (last[c]) {
            gao(last[c], i);
            return 0;
        }
        last[c] = i;
    }
    return 0;
}
