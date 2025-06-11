#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 9)
using namespace std;
typedef pair<int, int> pii;

int n, X[MAXN + 5], Y[MAXN + 5];
long long ans;

map<pii, int> mp;

bool check(int x, int y) {
    for (int t = x - 1; t <= x + 1; t++) if (mp.count(pii(t, y + 1))) {
        int cnt = 0;
        for (int w = t - 1; w <= t + 1; w++) if (mp.count(pii(w, y))) cnt++;
        if (cnt == 1) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        mp[pii(X[i], Y[i])] = i;
    }

    set<int> st;
    for (int i = 0; i < n; i++) if (check(X[i], Y[i])) st.insert(i);
    int step = 0;
    while (!st.empty()) {
        int idx;
        if (step % 2 == 0) idx = *prev(st.end());
        else idx = *(st.begin());

        ans = (ans * n + idx) % MOD;
        mp.erase(pii(X[idx], Y[idx]));
        st.erase(idx);
        step++;

        int y = Y[idx];
        for (int d = 0; d < 2; d++) for (int x = X[idx] - 2 + d; x <= X[idx] + 2 + d; x++) if (mp.count(pii(x, y - d))) {
            int t = mp[pii(x, y - d)];
            if (check(x, y - d)) st.insert(t);
            else st.erase(t);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
