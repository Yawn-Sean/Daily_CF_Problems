#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;
char s[MAXN + 5];

int gao(char c) {
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return -1;
    else return 2;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    vector<pii> vec;
    vec.push_back({0, 0});
    for (int i = 1, now = 0; i <= n; i++) {
        now += gao(s[i]);
        vec.push_back({now, i});
    }
    sort(vec.begin(), vec.end());

    int ans = 0, mn = 1e9;
    for (pii p : vec) {
        ans = max(ans, p.second - mn);
        mn = min(mn, p.second);
    }
    if (ans == 0) { printf("No solution\n"); return 0; }

    int now = 0, cnt = 0;
    for (int i = 1; i <= ans; i++) now += gao(s[i]);
    for (int i = ans; ; i++) {
        if (now >= 0) cnt++;
        if (i == n) break;
        now -= gao(s[i - ans + 1]);
        now += gao(s[i + 1]);
    }
    printf("%d %d\n", ans, cnt);
    return 0;
}
