#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L, X, Y; scanf("%d%d%d%d", &n, &L, &X, &Y);
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        st.insert(x);
    }

    int msk = 0;
    for (int x : st) {
        if (st.count(x + X)) msk |= 1;
        if (st.count(x + Y)) msk |= 2;
    }
    if (msk == 3) { printf("0\n"); return 0; }
    if (msk == 2) { printf("1\n%d\n", X); return 0; }
    if (msk == 1) { printf("1\n%d\n", Y); return 0; }

    auto gao = [&](int x) {
        if (x < 0 || x > L) return false;
        int msk = 0;
        if (st.count(x + X) || st.count(x - X)) msk |= 1;
        if (st.count(x + Y) || st.count(x - Y)) msk |= 2;
        return msk == 3;
    };

    for (int x : st) {
        if (gao(x + X)) { printf("1\n%d\n", x + X); return 0; }
        if (gao(x - X)) { printf("1\n%d\n", x - X); return 0; }
    }
    printf("2\n%d %d\n", X, Y);
    return 0;
}
