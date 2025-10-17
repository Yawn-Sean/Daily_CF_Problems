#include  <bits/stdc++.h>
using namespace std;

unordered_set<long long> st;

void dfs(int dep, long long now, int x, int y) {
    st.insert(now);
    if (dep < 10) {
        dfs(dep + 1, now * 10 + x, x, y);
        dfs(dep + 1, now * 10 + y, x, y);
    }
}

int main() {
    for (int i = 0; i <= 9; i++) for (int j = i + 1; j <= 9; j++) dfs(0, 0, i, j);

    int n; scanf("%d", &n);
    int ans = 0;
    for (long long x : st) {
        long long y = n - x;
        if (x <= y && st.count(y)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
