#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, A[MAXN + 10][2];
int root[MAXN + 10], sz[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        for (int j = 1; j <= n; j++) root[j] = j, sz[j] = 1;
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            int x = findroot(A[j][0]), y = findroot(A[j][1]);
            if (x == y) cnt++;
            else root[y] = x, sz[x] += sz[y];
        }
        vector<int> vec;
        for (int j = 1; j <= n; j++) if (j == findroot(j)) vec.push_back(sz[j]);
        sort(vec.begin(), vec.end(), greater<int>());
        int ans = 0;
        for (int j = 0; j <= cnt; j++) ans += vec[j];
        printf("%d\n", ans - 1);
    }
    return 0;
}
