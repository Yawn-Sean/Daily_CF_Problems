#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, ans;
char s[MAXN + 5];

bool check(int lim) {
    int now = 0, mn = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') now--;
        else now++;
        now = min(now, lim - 1);
        if (now < mn) mn = now, cnt = 1;
        else if (now == mn) cnt++;
    }
    return now == mn && cnt == 1;
}

void rev() {
    for (int i = 1; i <= n; i++)
        if (s[i] == 'L') s[i] = 'R';
        else s[i] = 'L';
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    if (check(MAXN + 5)) { printf("1\n"); return 0; }
    rev();
    if (check(MAXN + 5)) { printf("1\n"); return 0; }

    for (int t = 0; t < 2; t++) {
        rev();
        if (!check(1)) continue;
        int head = 1, tail = n;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (check(mid)) head = mid;
            else tail = mid - 1;
        }
        ans += head;
    }
    printf("%d\n", ans);
    return 0;
}
