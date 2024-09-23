#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
char s[N + 1];
int px[N + 1], py[N + 1];
int sx[N + 1], sy[N + 1];

int main() {
    int n;
    scanf("%d %s", &n, s);
    int x, y;
    scanf("%d %d", &x, &y);
    if (n < abs(x) + abs(y) || abs(x + y) % 2 != n % 2) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        py[i] = py[i - 1];
        px[i] = px[i - 1];
        if (s[i - 1] == 'U') py[i] += 1;
        if (s[i - 1] == 'D') py[i] -= 1;
        if (s[i - 1] == 'L') px[i] -= 1;
        if (s[i - 1] == 'R') px[i] += 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        sy[i] = sy[i + 1];
        sx[i] = sx[i + 1];
        if (s[i] == 'U') sy[i] += 1;
        if (s[i] == 'D') sy[i] -= 1;
        if (s[i] == 'L') sx[i] -= 1;
        if (s[i] == 'R') sx[i] += 1;
    }
    auto dist = [&] (int nx, int ny) {
        return abs(nx - x) + abs(ny - y);
    };
    if (dist(px[n], py[n]) == 0) {
        printf("0\n");
    } else {
        int ans = n;
        for (int l = 0, r = 0; l < n && r < n; l++) {
            while (dist(px[l] + sx[r + 1], py[l] + sy[r + 1]) > r - l + 1) {
                r++;
            }
            ans = min(ans, r - l + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

