#include <bits/stdc++.h>

using namespace std;
constexpr int N = 500;
char path[N * 2];

bool query(int r1, int c1, int r2, int c2) {
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    char res[4];
    scanf("%s", res);
    return strcmp(res, "YES") == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int x = 1, y = 1;
    int step = 0;
    for (int i = 1; i < n; i++) {
        if (query(x, y + 1, n, n)) {
            y++;
            path[step++] = 'R';
        } else {
            x++;
            path[step++] = 'D';
        }
    }
    x = n, y = n;
    step = 2 * n - 3;
    for (int i = 1; i < n; i++) {
        if (query(1, 1, x - 1, y)) {
            x--;
            path[step--] = 'D';
        } else {
            y--;
            path[step--] = 'R';
        }
    }
    printf("! %s\n", path);
    return 0;
}

