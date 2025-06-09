#include <bits/stdc++.h>
#define MAXN 200
using namespace std;
typedef pair<int, int> pii;

int f[4][4][MAXN + 5][MAXN + 5];
array<int, 4> from[4][4][MAXN + 5][MAXN + 5];

int dp(int i, int j, int a, int b) {
    if (i + j == 0) return a == 0 && b == 0 ? 1 : -1;
    int &ret = f[i][j][a][b];
    if (ret) return f[i][j][a][b];

    if (i > 0 && i + j < 5 && j < 3 && a >= 25) {
        for (int t = 0; t <= 23 && t <= b; t++) {
            if (dp(i - 1, j, a - 25, b - t) == 1) {
                from[i][j][a][b] = {i - 1, j, a - 25, b - t};
                return ret = 1;
            }
        }
        for (int t = 26; t <= a && t - 2 <= b; t++) {
            if (dp(i - 1, j, a - t, b - (t - 2)) == 1) {
                from[i][j][a][b] = {i - 1, j, a - t, b - (t - 2)};
                return ret = 1;
            }
        }
    }

    if (i == 3 && i + j == 5 && j < 3 && a >= 15) {
        for (int t = 0; t <= 13 && t <= b; t++) {
            if (dp(i - 1, j, a - 15, b - t) == 1) {
                from[i][j][a][b] = {i - 1, j, a - 15, b - t};
                return ret = 1;
            }
        }
        for (int t = 16; t <= a && t - 2 <= b; t++) {
            if (dp(i - 1, j, a - t, b - (t - 2)) == 1) {
                from[i][j][a][b] = {i - 1, j, a - t, b - (t - 2)};
                return ret = 1;
            }
        }
    }

    if (j > 0 && i + j < 5 && i < 3 && b >= 25) {
        for (int t = 0; t <= 23 && t <= a; t++) {
            if (dp(i, j - 1, a - t, b - 25) == 1) {
                from[i][j][a][b] = {i, j - 1, a - t, b - 25};
                return ret = 1;
            }
        }
        for (int t = 26; t <= b && t - 2 <= a; t++) {
            if (dp(i, j - 1, a - (t - 2), b - t) == 1) {
                from[i][j][a][b] = {i, j - 1, a - (t - 2), b - t};
                return ret = 1;
            }
        }
    }

    if (j == 3 && i + j == 5 && i < 3 && b >= 15) {
        for (int t = 0; t <= 13 && t <= a; t++) {
            if (dp(i, j - 1, a - t, b - 15) == 1) {
                from[i][j][a][b] = {i, j - 1, a - t, b - 15};
                return ret = 1;
            }
        }
        for (int t = 16; t <= b && t - 2 <= a; t++) {
            if (dp(i, j - 1, a - (t - 2), b - t) == 1) {
                from[i][j][a][b] = {i, j - 1, a - (t - 2), b - t};
                return ret = 1;
            }
        }
    }

    return ret = -1;
}

void print(int i, int j, int a, int b) {
    printf("%d:%d\n", i, j);
    vector<pii> vec;
    while (i + j > 0) {
        auto &[ii, jj, aa, bb] = from[i][j][a][b];
        vec.push_back({a - aa, b - bb});
        i = ii; j = jj; a = aa; b = bb;
    }
    while (true) {
        printf("%d:%d", vec.back().first, vec.back().second);
        vec.pop_back();
        if (vec.size() > 0) printf(" ");
        else { printf("\n"); break; }
    }
}

void solve() {
    int a, b; scanf("%d%d", &a, &b);
    for (int i = 0; i <= 2; i++) if (dp(3, i, a, b) == 1) {
        print(3, i, a, b);
        return;
    }
    for (int i = 2; i >= 0; i--) if (dp(i, 3, a, b) == 1) {
        print(i, 3, a, b);
        return;
    }
    printf("Impossible\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
