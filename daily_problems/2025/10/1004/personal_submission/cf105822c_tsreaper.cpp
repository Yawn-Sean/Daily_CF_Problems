#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
char s[MAXN + 5];

void solve() {
    scanf("%d%s", &n, s + 1);

    int odd = 0;
    for (int i = 1; i <= n; i++) if (s[i] == 'O') odd++;
    if ((odd & 1) != (n & 1)) { printf("NO\n"); return; }

    vector<int> vec[2];
    for (int i = 1; i <= n * 2; i++) vec[i & 1].push_back(i);
    for (int p = 0; p < 2; p++) reverse(vec[p].begin(), vec[p].end());
    printf("YES\n");
    for (int i = 1, j = 0; i <= n; i++) {
        int x, y;
        if (s[i] == 'O') {
            x = vec[0].back(); vec[0].pop_back();
            y = vec[1].back(); vec[1].pop_back();
        } else {
            if (j == 0) {
                x = vec[1].back(); vec[1].pop_back();
                y = vec[1].back(); vec[1].pop_back();
            } else {
                x = vec[0].back(); vec[0].pop_back();
                y = vec[0].back(); vec[0].pop_back();
            }
            j ^= 1;
        }
        printf("%d %d\n", x, y);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
