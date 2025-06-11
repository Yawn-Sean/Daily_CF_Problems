#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
char s1[MAXN + 5], s2[MAXN + 5];
vector<pii> ans;

int root[26];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    for (int i = 0; i < 26; i++) root[i] = i;
    for (int i = 1; i <= n; i++) {
        int x = findroot(s1[i] - 'a'), y = findroot(s2[i] - 'a');
        if (x == y) continue;
        root[x] = y;
        ans.push_back({x, y});
    }
    printf("%d\n", ans.size());
    for (pii p : ans) printf("%c %c\n", p.first + 'a', p.second + 'a');
    return 0;
}
