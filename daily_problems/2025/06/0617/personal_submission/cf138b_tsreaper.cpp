#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
char s[MAXN + 5], ans1[MAXN + 5], ans2[MAXN + 5];

int cnt[2][10];

int gao(int x, int y) {
    int ret = x * 2;
    if (y == 0) return ret;
    cnt[0][0] -= x; cnt[1][0] -= x;
    cnt[0][y]--; cnt[1][10 - y]--;
    if (cnt[0][y] < 0 || cnt[1][10 - y] < 0) ret = -1e9;
    else {
        ret++;
        for (int i = 0; i < 10; i++) ret += min(cnt[0][i], cnt[1][9 - i]);
    }
    cnt[0][0] += x; cnt[1][0] += x;
    cnt[0][y]++; cnt[1][10 - y]++;
    return ret;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int d = s[i] - '0';
        cnt[0][d]++; cnt[1][d]++;
    }

    int x = -1, y = -1, best = -1;
    for (int i = 0; i <= cnt[0][0]; i++) for (int j = 0; j <= 9; j++) {
        int t = gao(i, j);
        if (t > best) x = i, y = j, best = t;
    }

    int now = n;
    for (int i = 1; i <= x; i++, now--) ans1[now] = ans2[now] = '0';
    cnt[0][0] -= x; cnt[1][0] -= x;

    if (y > 0) {
        ans1[now] = y + '0'; ans2[now] = 10 - y + '0'; now--;
        cnt[0][y]--; cnt[1][10 - y]--;
        for (int i = 0; i < 10; i++) {
            int t = min(cnt[0][i], cnt[1][9 - i]);
            for (int j = 1; j <= t; j++, now--) ans1[now] = i + '0', ans2[now] = 9 - i + '0';
            cnt[0][i] -= t; cnt[1][9 - i] -= t;
        }
    }

    int now1 = now, now2 = now;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= cnt[0][i]; j++, now1--) ans1[now1] = i + '0';
        for (int j = 1; j <= cnt[1][i]; j++, now2--) ans2[now2] = i + '0';
    }

    printf("%s\n%s\n", ans1 + 1, ans2 + 1);
    return 0;
}
