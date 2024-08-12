#include <bits/stdc++.h>
#define MAXLEN ((int) 1e5)
#define SIGMA 26
using namespace std;

int n;
char s[MAXLEN + 10];

unordered_set<int> e[SIGMA + 5];
bool used[SIGMA + 5];
int deg[SIGMA + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        bool vis[SIGMA + 5] = {0};
        for (int j = 1; s[j]; j++) {
            int x = s[j] - 'a', y = s[j - 1] - 'a';
            if (vis[x]) { printf("NO\n"); return 0; }
            used[x] = vis[x] = true;
            if (j > 1 && e[y].count(x) == 0) e[y].insert(x), deg[x]++;
        }
    }

    for (int i = 0; i < 26; i++) if (e[i].size() > 1 || deg[i] > 1) { printf("NO\n"); return 0; }
    string ans;
    for (int i = 0; i < 26; i++) if (used[i] && deg[i] == 0) {
        for (int now = i; ; now = *(e[now].begin())) {
            ans.push_back(now + 'a');
            if (e[now].size() == 0) break;
        }
    }
    int tot = 0;
    for (int i = 0; i < 26; i++) if (used[i]) tot++;
    if (ans.size() == tot) printf("%s\n", ans.c_str());
    else printf("NO\n");
    return 0;
}
