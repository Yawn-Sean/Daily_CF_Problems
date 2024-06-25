#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, K, q, A[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), st.insert(A[i]);

    scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        int ans = K + 1;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= K; j++) {
            int rem = x - A[i] * j;
            if (rem > 0) {
                for (int k = 1; j + k <= K; k++)
                    if (rem % k == 0 && st.count(rem / k))
                        ans = min(ans, j + k);
            } else if (rem == 0) {
                ans = min(ans, j);
            }
        }
        printf("%d\n", ans <= K ? ans : -1);
    }
    return 0;
}
