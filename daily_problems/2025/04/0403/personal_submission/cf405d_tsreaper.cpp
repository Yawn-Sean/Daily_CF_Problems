#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MAXA ((int) 1e6)
using namespace std;

int n, A[MAXN + 5];
vector<int> ans;

bool vis[MAXA + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        vis[A[i]] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[MAXA + 1 - A[i]]) ans.push_back(MAXA + 1 - A[i]);
        else cnt++;
    }
    cnt /= 2;
    for (int i = 1; i <= MAXA && cnt > 0; i++) if (!vis[i] && !vis[MAXA + 1 - i]) {
        ans.push_back(i);
        ans.push_back(MAXA + 1 - i);
        cnt--;
    }
    
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
