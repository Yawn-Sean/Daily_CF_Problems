#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans, A[MAXN * 2 + 10];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++) scanf("%d", &A[i]);

    int goal = 0;
    for (int i = 1; i <= n * 2; i++)
        if (A[i] == 1) goal++;
        else goal--;

    unordered_map<int, int> mp;
    mp[0] = 0;
    for (int i = n + 1, now = 0; i <= n * 2; i++) {
        if (A[i] == 1) now++;
        else now--;
        if (!mp.count(now)) mp[now] = i - n;
    }

    ans = n * 2;
    if (mp.count(goal)) ans = min(ans, mp[goal]);
    for (int i = n, now = 0; i > 0; i--) {
        if (A[i] == 1) now++;
        else now--;
        int t = goal - now;
        if (mp.count(t)) ans = min(ans, n - i + 1 + mp[t]);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
