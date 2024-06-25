#include <iostream>

const int N = 2e5;
int n, a[N + 10][2];
bool vis[N + 10];

int main() {
    scanf("%d", &n); for (int i = 1; i <= n; i++)
        scanf("%d%d", a[i], a[i] + 1);
    int cur = 1; vis[cur] = true, printf("%d ", cur); for (int i = 0; i < n; i++)
        if (a[a[cur][0]][0] == a[cur][1] || a[a[cur][0]][1] == a[cur][1]) {
            if (vis[a[cur][0]])
                break;
            printf("%d ", a[cur][0]), vis[a[cur][0]] = true;
            if (vis[a[cur][1]])
                break;
            printf("%d ", a[cur][1]); vis[a[cur][1]] = true, cur = a[cur][1];
        } else {
            if (vis[a[cur][1]])
                break;
            printf("%d ", a[cur][1]), vis[a[cur][1]] = true;
            if (vis[a[cur][0]])
                break;
            printf("%d ", a[cur][0]); vis[a[cur][0]] = true, cur = a[cur][0];
        }
    return 0;
}
