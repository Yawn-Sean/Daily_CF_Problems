#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, E[MAXM + 5][3];

int root[MAXN + 5];
vector<int> vec;

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        char s[3];
        scanf("%d%d%s", &E[i][0], &E[i][1], s);
        E[i][2] = (s[0] == 'S' ? 1 : 0);
    }
    if (n % 2 == 0) { printf("-1\n"); return 0; }

    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) {
        int x = findroot(E[i][0]), y = findroot(E[i][1]);
        if (x == y) continue;
        root[x] = y;
        vec.push_back(i);
    }
    if (vec.size() != n - 1) { printf("-1\n"); return 0; }

    int cnt = 0;
    for (int i : vec) cnt += E[i][2];

    auto gao = [&](int i) {
        for (int j = 1; j <= n; j++) root[j] = j;
        vector<int> tmp = {i};
        root[E[i][0]] = E[i][1];
        for (int j : vec) {
            int x = findroot(E[j][0]), y = findroot(E[j][1]);
            if (x == y) continue;
            root[x] = y;
            tmp.push_back(j);
        }
        vec = tmp;
        cnt = 0;
        for (int j : vec) cnt += E[j][2];
    };

    for (int i = 1; i <= m; i++) if (E[i][0] != E[i][1]) {
        if (cnt < n / 2 && E[i][2] == 1) gao(i);
        if (cnt > n / 2 && E[i][2] == 0) gao(i);
    }
    if (cnt != n / 2) printf("-1\n");
    else {
        printf("%d\n", vec.size());
        for (int i = 0; i < vec.size(); i++) printf("%d%c", vec[i], "\n "[i + 1 < vec.size()]);
    }
    return 0;
}
