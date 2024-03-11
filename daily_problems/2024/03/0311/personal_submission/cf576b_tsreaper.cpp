#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];

bool vis[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<vector<int>> vec;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vec.push_back({});
        for (int j = i; !vis[j]; j = A[j]) {
            vec.back().push_back(j);
            vis[j] = true;
        }
    }

    int one = -1;
    for (int i = 0; i < vec.size(); i++) if (vec[i].size() == 1) { one = i; break; }
    if (one >= 0) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) if (i != vec[one][0]) printf("%d %d\n", i, vec[one][0]);
        return 0;
    }

    int two = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].size() % 2 == 1) { printf("NO\n"); return 0; }
        else if (vec[i].size() == 2) two = i;
    }
    if (two < 0) { printf("NO\n"); return 0; }

    printf("YES\n");
    printf("%d %d\n", vec[two][0], vec[two][1]);
    for (int i = 0; i < vec.size(); i++) if (i != two) {
        for (int j = 0; j < vec[i].size(); j++) printf("%d %d\n", vec[i][j], vec[two][j & 1]);
    }
    return 0;
}
