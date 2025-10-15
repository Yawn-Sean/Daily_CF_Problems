#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<int, int> pii;

int n, K;
char s[MAXN + 5];

char goal[MAXN + 5];

void solve() {
    scanf("%d%d%s", &n, &K, s + 1);
    
    for (int i = 1; K > 0; K--) {
        if (K > 1) {
            goal[i] = '(';
            goal[i + 1] = ')';
            i += 2;
        } else {
            int rem = n - i + 1;
            for (int j = 1; j <= rem / 2; j++) goal[i++] = '(';
            for (int j = 1; j <= rem / 2; j++) goal[i++] = ')';
        }
    }

    vector<pii> ans;
    for (int i = 1; i <= n; i++) if (s[i] != goal[i]) {
        int j = i;
        for (; s[j] != goal[i]; j++);
        ans.push_back({i, j});
        reverse(s + i, s + j + 1);
    }
    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
