#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
bool flag[MAXN * 2 + 10];

int idx(int x) {
    if (x == 2) return n;
    if (x == n) return 2;
    return x;
}

void print(int x, int y, int z) {
    printf("%d %d %d\n", idx(x), idx(y), z);
}

int main() {
    scanf("%d%d", &n, &m);
    flag[0] = flag[1] = true;
    for (int i = 2; i <= n * 2; i++) if (!flag[i]) for (int j = i * 2; j <= n * 2; j += i) flag[j] = true;

    int goal = 0;
    for (int i = n; i <= (n - 1) * 2; i++) if (!flag[i]) { goal = i; break; }
    assert(goal > 0);
    printf("2 %d\n", goal);
    print(1, 2, 2); goal -= 2;
    for (int i = 2; i < n; i++) {
        if (goal > n - i) print(i, i + 1, 2), goal -= 2;
        else print(i, i + 1, 1), goal -= 1;
    }
    for (int i = n, x = 1, y = 3; i <= m; i++) {
        print(x, y, 1e9);
        y++;
        if (y > n) x++, y = x + 2;
    }
    return 0;
}
