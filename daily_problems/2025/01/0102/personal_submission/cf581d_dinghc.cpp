#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
const char* s = "ABC";
char billboard[N + 1][N + 1];

int main() {
    array<int, 2> p[3];
    scanf("%d%d%d%d%d%d", &p[0][0], &p[0][1], &p[1][0], &p[1][1], &p[2][0], &p[2][1]);
    int n = max({p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]});
    if (n * n != p[0][0] * p[0][1] + p[1][0] * p[1][1] + p[2][0] * p[2][1]) {
        printf("-1\n");
        return 0;
    }
    if (p[0][0] < p[0][1]) swap(p[0][0], p[0][1]);
    if (p[1][0] < p[1][1]) swap(p[1][0], p[1][1]);
    if (p[2][0] < p[2][1]) swap(p[2][0], p[2][1]);
    auto fill = [&] (char c, int l, int t, int r, int b) {
        for (int x = l; x <= r; x++) {
            for (int y = t; y <= b; y++) {
                billboard[x][y] = c;
            }
        }
    };
    bool ans = false;
    if (p[0][0] == n && p[1][0] == n && p[2][0] == n) {
        ans = true;
        fill(s[0], 0, 0, n - 1, p[0][1] - 1);
        fill(s[1], 0, p[0][1], n - 1, p[0][1] + p[1][1] - 1);
        fill(s[2], 0, p[0][1] + p[1][1], n - 1, n - 1);
    } else {
        for (int i = 0; i < 3; i++) {
            if (p[i][0] == n) {
                int j = (i + 1) % 3;
                int k = (i + 2) % 3;
                vector<pair<int, int>> pi {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
                for (auto&[x, y] : pi) {
                    if (p[j][x] == p[k][y] && p[j][x ^ 1] + p[k][y ^ 1] == n) {
                        fill(s[i], 0, 0, n - 1, p[i][1] - 1);
                        fill(s[j], 0, p[i][1], p[j][x ^ 1] - 1, n - 1);
                        fill(s[k], p[j][x ^ 1], p[i][1], n - 1, n - 1);
                        ans = true;
                        break;
                    }
                }
                if (ans) break;
            }
        }
    }
    if (!ans) {
        printf("-1\n");
    } else {
        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            billboard[i][n] = '\0';
            printf("%s\n", billboard[i]);
        }
    }
    return 0;
}

