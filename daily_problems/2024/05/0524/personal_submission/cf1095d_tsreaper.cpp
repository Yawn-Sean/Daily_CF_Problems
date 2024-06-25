#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
 
int n;
 
vector<int> e[MAXN + 10];
unordered_set<int> st[MAXN + 10];
bool vis[MAXN + 10];
 
void dfs(int sn) {
    printf("%d ", sn);
    vis[sn] = true;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (vis[fn] || st[sn].count(fn) == 0) continue;
        dfs(fn);
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        st[i].insert(x); st[i].insert(y);
    }
    
    dfs(1);
    printf("\n");
    return 0;
}
