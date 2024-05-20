#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, ans;
char s[MAXN + 10];

int pre[MAXN + 10], nxt[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    
    vector<int> vec;
    for (int i = 1; i <= n; i++)
        if ((i > 1 && s[i] != s[i - 1]) || (i < n && s[i] != s[i + 1]))
            vec.push_back(i);
    
    for (int i = 1; i <= n; i++) pre[i] = i - 1, nxt[i] = i + 1;
    while (vec.size() > 0) {
        ans++;
        vector<int> tmp;
        for (int x : vec) if (!vis[x]) {
            vis[x] = true;
            tmp.push_back(pre[x]); tmp.push_back(nxt[x]);
            nxt[pre[x]] = nxt[x]; pre[nxt[x]] = pre[x];
        }

        vec.clear();
        for (int x : tmp) if (x > 0 && x <= n && !vis[x])
            if ((pre[x] > 0 && s[x] != s[pre[x]]) || (nxt[x] <= n && s[x] != s[nxt[x]]))
                vec.push_back(x);
    }

    printf("%d\n", ans);
    return 0;
}
