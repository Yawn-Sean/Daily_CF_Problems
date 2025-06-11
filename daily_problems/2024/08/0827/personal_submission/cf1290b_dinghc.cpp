#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
constexpr int A = 26;
char s[N + 1];
int a[N + 1][A];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < A; j++) {
            a[i][j] = a[i - 1][j];
        }
        a[i][s[i - 1] - 'a'] += 1;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0, x, y; i < q; i++) {
        scanf("%d%d", &x, &y);
        int k = 0;
        for (int j = 0; j < A; j++) {
            k += (a[y][j] - a[x - 1][j]) > 0;
        }
        if (x == y || s[x - 1] != s[y - 1]) {
            printf("YES\n");
        } else if (k > 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

