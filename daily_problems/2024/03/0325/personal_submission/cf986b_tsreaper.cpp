#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, A[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = true;
        for (int j = A[i]; j != i; j = A[j]) cnt++, vis[j] = true;
    }

    if (n * 3 % 2 == cnt % 2) printf("Petr\n");
    else printf("Um_nik\n");
    return 0;
}
