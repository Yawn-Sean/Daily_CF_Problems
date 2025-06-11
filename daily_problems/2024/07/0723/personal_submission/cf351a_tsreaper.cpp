#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int sm = 0, cnt = 0;
    for (int i = 1; i <= n * 2; i++) {
        char s[15]; scanf("%s", s);
        int p;
        for (p = 0; s[p] != '.'; p++);
        int t = atoi(s + p + 1);
        if (t > 0) sm += t, cnt++;
    }

    int ans = 1e9;
    for (int i = max(0, cnt - n); i <= n && i <= cnt; i++)
        ans = min(ans, abs(1000 * i - sm));
    printf("%.3f\n", ans / 1000.0);
    return 0;
}
