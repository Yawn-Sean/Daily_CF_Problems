#include  <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, K;
char s[MAXN + 5], ans[MAXN + 5];

int f[MAXN + 5];
vector<int> vec[MAXN + 5];

int main() {
    scanf("%d%d%s", &n, &K, s + 1);

    vector<int> pos[3];
    for (int i = 1; i <= n; i++) {
        int x;
        if (s[i] == 'S') x = 0;
        else if (s[i] == 'P') x = 1;
        else x = 2;
        int y = (x + 1) % 3;

        int a = pos[x].empty() ? 0 : pos[x].back();
        int b = pos[y].empty() ? 0 : pos[y].back();
        if (a >= b) f[i] = f[a] + i - a - 1;
        else f[i] = (f[b] ? i - b - 1 : 0);
        f[i] = min(f[i], K);

        vec[i - f[i]].push_back(i);
        pos[x].push_back(i);
    }

    set<int> st;
    for (int i = 1; i <= n; i++) {
        for (int x : vec[i]) st.insert(x);
        auto it = prev(st.end());
        ans[i] = s[*it];
        st.erase(it);
    }
    printf("%s\n", ans + 1);
    return 0;
}
