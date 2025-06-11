#include <bits/stdc++.h>
#define MAXN ((int) 4e5)
using namespace std;
typedef pair<int, int> pii;

int n, K, ans, A[MAXN + 10];

int nxt[MAXN + 10], pos[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) pos[i] = n + 1;
    for (int i = n; i > 0; i--) {
        nxt[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    set<pii> st;
    for (int i = 1; i <= n; i++) {
        if (vis[A[i]]) {
            st.erase(pii(i, A[i]));
            st.insert(pii(nxt[i], A[i]));
        } else {
            if (st.size() == K) {
                pii p = *prev(st.end());
                vis[p.second] = false;
                st.erase(p);
            }
            st.insert(pii(nxt[i], A[i]));
            vis[A[i]] = true;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
