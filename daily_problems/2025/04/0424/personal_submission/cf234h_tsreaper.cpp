#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN * 2 + 5];

pair<vector<int>, vector<int>> gao(int x) {
    vector<int> ret1, ret2;
    int i = 1, j = n + 1;
    while (i <= n || j <= n + m) {
        while (i <= n && A[i] == x) ret2.push_back(i), i++;
        while (j <= n + m && A[j] == x) ret2.push_back(j), j++;
        x ^= 1;
    }
    for (int i = 0; i + 1 < ret2.size(); i++) if (A[ret2[i]] != A[ret2[i + 1]]) ret1.push_back(i + 1);
    if (A[ret2.back()] == 1) ret1.push_back(ret2.size());
    return make_pair(ret1, ret2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &A[i + n]);

    auto ans1 = gao(0), ans2 = gao(1);
    if (ans1.first.size() > ans2.first.size()) swap(ans1, ans2);
    for (int x : ans1.second) printf("%d ", x);
    printf("\n%d\n", ans1.first.size());
    for (int x : ans1.first) printf("%d ", x);
    printf("\n");
    return 0;
}
