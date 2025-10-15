#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> ans, vec[MAXN + 5];

int main() {
    scanf("%d", &n);

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec[x].push_back(i);
        mx = max(mx, x);
    }

    int now = 0;
    while (now >= 0) {
        if (vec[now].empty()) now -= 3;
        else {
            ans.push_back(vec[now].back());
            vec[now].pop_back();
            now++;
        }
    }

    if (ans.size() == n) {
        printf("Possible\n");
        for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
