#include <bits/stdc++.h>
using namespace std;

int main() {
    int B1, q, LIM, n; scanf("%d%d%d%d", &B1, &q, &LIM, &n);
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        st.insert(x);
    }

    if (abs(B1) > LIM) {
        printf("0\n");
    } else if (B1 == 0) {
        if (st.count(0)) printf("0\n");
        else printf("inf\n");
    } else if (q == 0) {
        if (st.count(0)) {
            if (st.count(B1)) printf("0\n");
            else printf("1\n");
        } else {
            printf("inf\n");
        }
    } else if (q == 1) {
        if (st.count(B1)) printf("0\n");
        else printf("inf\n");
    } else if (q == -1) {
        if (st.count(B1) && st.count(-B1)) printf("0\n");
        else printf("inf\n");
    } else {
        int cnt = 0;
        long long now = B1;
        while (abs(now) <= LIM) {
            if (!st.count(now)) cnt++;
            now *= q;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
