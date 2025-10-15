#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10];

bool flag[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) if (i == 1 || i == n || A[i] == A[i + 1] || A[i] == A[i - 1]) flag[i] = true;
    vector<pii> vec;
    for (int i = 1, j = 1; i <= n + 1; i++) if (!flag[i]) {
        if (j < i) vec.push_back({j, i - 1});
        j = i + 1;
    }
    int ans = 0;
    for (int i = 1; i < vec.size(); i++) {
        ans = max(ans, (vec[i].first - vec[i - 1].second) / 2);
        for (int l = vec[i - 1].second + 1, r = vec[i].first - 1; l <= r; l++, r--) {
            A[l] = A[vec[i - 1].second];
            A[r] = A[vec[i].first];
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
