#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
#define INF ((int) 1e9)
using namespace std;

int main() {
    long long ans = 1;
    set<int> st;
    st.insert(-INF); st.insert(INF);
    int L = -INF, R = INF;

    int q; scanf("%d", &q);
    while (q--) {
        char s[10]; scanf("%s", s);
        int x; scanf("%d", &x);
        if (s[1] == 'D') st.insert(x);
        else {
            auto it = st.find(x);
            if (it == st.end()) { printf("0\n"); return 0; }
            if (*it < L || *it > R) { printf("0\n"); return 0; }
            if (*it > L && *it < R) ans = ans * 2 % MOD;
            L = *prev(it); R = *next(it);
            st.erase(it);
        }
    }

    int cnt = 1;
    for (int x : st) if (x > L && x < R) cnt++;
    ans = ans * cnt % MOD;
    printf("%lld\n", ans);
    return 0;
}
