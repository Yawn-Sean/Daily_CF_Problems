#include <bits/stdc++.h>
#define MAXN 4000
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5];
long long C[MAXN + 5];
vector<int> ans;

bool vis[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%lld", &A[i], &B[i], &C[i]);
    
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        ans.push_back(i);
        for (int val = A[i], j = i + 1; j <= n; j++) if (!vis[j] && val > 0) C[j] -= val, val--;
        for (int j = i + 1; j <= n; j++) if (!vis[j] && C[j] < 0) {
            vis[j] = true;
            for (int k = j + 1; k <= n; k++) if (!vis[k]) C[k] -= B[j];
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
    return 0;
}
