#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
char s[MAXN + 10];

bool check(int lim) {
    int L, R;
    for (int i = 1; i <= n; i++) if (s[i] != '.') { L = i; break; }
    for (int i = n; i > 0; i--) if (s[i] != '.') { R = i; break; }

    int now = L - 1;
    for (int i = 1; i <= n; i++) if (s[i] == 'P') {
        now = min(now + 1, i);
        while (s[now] == '.') now++;
        int det = i - now;
        if (lim < det) return false;
        int v1 = lim - det * 2, v2 = (lim - det) / 2;
        now = i + max(v1, v2);
    }
    return now >= R;
}

int main() {
    scanf("%d%s", &n, s + 1);
    int head = 0, tail = n * 2;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
