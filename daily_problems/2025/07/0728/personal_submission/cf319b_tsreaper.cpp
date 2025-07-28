#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, list<int>::iterator> pit;

int n, ans;
list<int> lst;

bool vis[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        lst.push_back(x);
    }

    vector<pit> vec;
    for (auto it = lst.begin(); next(it) != lst.end(); it++)
        if (*it > *next(it)) vec.push_back({*it, it});
    reverse(vec.begin(), vec.end());

    while (true) {
        ans++;
        int cnt = 0;
        vector<pit> nxt;
        for (pit p : vec) if (!vis[p.first]) {
            cnt++;
            auto it = p.second;
            vis[*next(it)] = true;
            lst.erase(next(it));
            if (next(it) != lst.end() && *it > *next(it)) nxt.push_back({*it, it});
        }
        if (cnt == 0) { ans--; break; }
        vec = nxt;
    }
    printf("%d\n", ans);
    return 0;
}
