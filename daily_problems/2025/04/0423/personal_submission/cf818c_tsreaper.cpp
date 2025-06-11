#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, W, H, L, R, U, D;
unordered_set<int> X[MAXN + 5], Y[MAXN + 5];

int cnt[MAXN + 5][4];

int main() {
    scanf("%d%d%d", &n, &W, &H);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 2; j++) {
        int x, y; scanf("%d%d", &x, &y);
        X[x].insert(i); Y[y].insert(i);
    }
    scanf("%d%d%d%d", &L, &R, &U, &D);

    unordered_set<int> st;
    for (int i = 1; i <= W; i++) {
        for (int t : X[i]) {
            int v = st.size();
            if (X[i - 1].count(t)) v--;
            cnt[t][0] = max(cnt[t][0], v);
        }
        for (int t : X[i]) st.insert(t);
    }

    st.clear();
    for (int i = W; i > 0; i--) {
        for (int t : X[i]) {
            int v = st.size();
            if (X[i + 1].count(t)) v--;
            cnt[t][1] = max(cnt[t][1], v);
        }
        for (int t : X[i]) st.insert(t);
    }

    st.clear();
    for (int i = 1; i <= H; i++) {
        for (int t : Y[i]) {
            int v = st.size();
            if (Y[i - 1].count(t)) v--;
            cnt[t][2] = max(cnt[t][2], v);
        }
        for (int t : Y[i]) st.insert(t);
    }

    st.clear();
    for (int i = H; i > 0; i--) {
        for (int t : Y[i]) {
            int v = st.size();
            if (Y[i + 1].count(t)) v--;
            cnt[t][3] = max(cnt[t][3], v);
        }
        for (int t : Y[i]) st.insert(t);
    }

    for (int i = 1; i <= n; i++) if (cnt[i][0] == L && cnt[i][1] == R && cnt[i][2] == U && cnt[i][3] == D) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
