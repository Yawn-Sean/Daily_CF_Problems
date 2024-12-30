#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q, A[MAXN + 10];

long long f[MAXN + 10];
unordered_set<long long> st;

void gao(int L, int R) {
    st.insert(f[R] - f[L - 1]);
    if (A[L] == A[R]) return;
    int goal = (A[L] + A[R]) >> 1;

    int head = L, tail = R;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (A[mid] <= goal) head = mid;
        else tail = mid - 1;
    }

    gao(L, head); gao(head + 1, R);
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i];

    st.clear();
    gao(1, n);

    while (q--) {
        int x; scanf("%d", &x);
        if (st.count(x)) printf("Yes\n");
        else printf("No\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
