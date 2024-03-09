#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
char s1[MAXN + 10], s2[MAXN + 10];

bool check(int l, int r) {
    for (int i = l, j = 1; i <= r; i++) {
        while (j <= n && s1[j] != s2[i]) j++;
        if (j > n) return false;
        j++;
    }
    return true;
}

bool check(int len) {
    for (int r = len; r <= n; r++) if (check(r - len + 1, r)) return true;
    return false;
}

void solve() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);

    int cnt[26] = {0};
    for (int i = 1; i <= n; i++) cnt[s1[i] - 'a']++;
    for (int i = 1; i <= n; i++) cnt[s2[i] - 'a']--;
    for (int i = 0; i < 26; i++) if (cnt[i] != 0) { printf("-1\n"); return; }

    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", n - head);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
