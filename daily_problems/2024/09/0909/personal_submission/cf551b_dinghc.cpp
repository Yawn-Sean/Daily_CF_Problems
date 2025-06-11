#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
char a[N + 1];
char b[N + 1];
char c[N + 1];
char ans[N + 1];

int main() {
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    int m = strlen(a);
    int n = strlen(b);
    int k = strlen(c);
    array<int, 26> fa{};
    array<int, 26> fb{};
    array<int, 26> fc{};
    for (int i = 0; i < m; i++) {
        fa[a[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        fb[b[i] - 'a']++;
    }
    for (int i = 0; i < k; i++) {
        fc[c[i] - 'a']++;
    }
    int cnt_b = m + 1;
    for (int i = 0; i < 26; i++) {
        if (fb[i] == 0) continue;
        cnt_b = min(cnt_b, fa[i] / fb[i]);
    }
    cnt_b %= m + 1;
    pair<int, int> mx{};
    for (int x = 0; x <= cnt_b; x++) {
        int y = m + 1;
        for (int i = 0; i < 26; i++) {
            if (fc[i] == 0) continue;
            y = min(y, (fa[i] - x * fb[i]) / fc[i]);
        }
        y %= m + 1;
        mx = max(mx, {x + y, x});
    }
    int x = mx.second;
    int y = mx.first - x;
    int j = 0;
    for (int i = 0; i < x; i++) {
        strcpy(&ans[j], b);
        j += n;
    }
    for (int i = 0; i < y; i++) {
        strcpy(&ans[j], c);
        j += k;
    }
    for (int i = 0; i < 26; i++) {
        int cnt = fa[i] - x * fb[i] - y * fc[i];
        while (cnt--) {
            ans[j++] = 'a' + i;
        }
    }
    ans[m] = '\0';
    printf("%s\n", ans);
    return 0;
}

