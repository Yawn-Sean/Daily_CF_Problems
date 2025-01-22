#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m, B[MAXN * 2 + 5];
pii A[MAXN * 2 + 5];

bool used[MAXN * 2 + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) scanf("%d", &A[i].first), A[i].second = i;
    vector<pii> vec;
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        if (A[x].first < A[y].first) swap(x, y);
        B[x] = y; B[y] = x;
        vec.push_back({x, y});
    }
    sort(A + 1, A + n * 2 + 1, greater<pii>());
    int who; scanf("%d", &who);
    for (int r = 1, last = 0, i = 1; r <= n * 2; r++) {
        if (r % 2 == who % 2) {
            int t = 0;
            if (B[last] && !used[B[last]]) t = B[last];
            else {
                while (!vec.empty()) {
                    if (used[vec.back().first]) vec.pop_back();
                    else { t = vec.back().first; break; }
                }
                if (t == 0) {
                    while (i <= n * 2 && used[A[i].second]) i++;
                    t = A[i].second;
                }
            }
            printf("%d\n", t); fflush(stdout);
            used[t] = true;
        } else {
            scanf("%d", &last);
            used[last] = true;
        }
    }
    return 0;
}
