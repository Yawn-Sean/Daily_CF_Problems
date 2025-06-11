#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
char s[N][N + 1];

int main() {
    vector<char> tb(62, ' ');
    for (int i = 0; i <= 9; i++) tb[i] = i + '0';
    for (int i = 0; i <= 25; i++) tb[i + 10] = i + 'a';
    for (int i = 0; i <= 25; i++) tb[i + 36] = i + 'A';
    int t;
    scanf("%d", &t);
    while (t--) {
        int r, c, k;
        scanf("%d%d%d", &r, &c, &k);
        int tot = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < c; j++) {
                if (s[i][j] == 'R') tot++;
            }
        }
        auto get = [&] (int j) -> pair<int, int> {
            int x = j / c;
            int y = j % c;
            if (x & 1) y = c - y - 1;
            return pair<int, int> {x, y};
        };
        int avg = tot / k;
        int p = tot % k;
        int j = 0;
        char clr = tb[0];
        for (int i = 0; i < k; i++) {
            clr = tb[i];
            int curr = avg + (i < p ? 1 : 0);
            while (curr) {
                auto [x, y] = get(j++);
                if (s[x][y] == 'R') curr--;
                s[x][y] = clr;
            }
        }
        while (j < r * c) {
            auto [x, y] = get(j++);
            s[x][y] = clr;
        }
        for (int i = 0; i < r; i++) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}

