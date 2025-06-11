#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m, A[MAXN + 5], B[MAXN + 5];

bool check(int X) {
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        X += A[i];
        st.insert(X);
    }
    for (int i = 1; i <= m; i++) if (!st.count(B[i])) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);

    unordered_set<int> st;
    for (int i = 1, now = 0; i <= n; i++) {
        now += A[i];
        int x = B[1] - now;
        if (check(x)) st.insert(x);
    }
    printf("%d\n", st.size());
    return 0;
}
