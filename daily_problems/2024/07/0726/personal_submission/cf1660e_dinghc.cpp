#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2000;
char s[N + 1][N + 1];

int solve() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; j++) {
            tot += s[i][j] == '1';
        }
    }
    int mx = 0;
    for (int d = 0; d < n; d++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            if (s[(j + d) % n][j] == '1') {
                curr += 1;
            }
        }
        mx = max(mx, curr);
    }
    return n - mx + (tot - mx);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int res = solve();
        printf("%d\n", res);
    }
    return 0;
}

