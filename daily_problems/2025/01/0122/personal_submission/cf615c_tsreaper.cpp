#include <bits/stdc++.h>
#define MAXN 2100
using namespace std;
typedef pair<int, int> pii;

int n, m;
char s1[MAXN + 5], s2[MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);

    vector<int> pos[26];
    for (int i = 1; i <= n; i++) pos[s1[i] - 'a'].push_back(i);

    vector<pii> ans, vec;
    for (int i = 1; i <= m; i++) {
        vector<pii> nxt;
        for (pii p : vec) {
            int idx = p.first + p.second;
            if (p.second > 0) {
                if (idx <= n && s1[idx] == s2[i]) nxt.push_back({p.first, p.second + 1});
            } else {
                if (idx > 0 && s1[idx] == s2[i]) nxt.push_back({p.first, p.second - 1});
            }
        }

        if (nxt.empty()) {
            if (!vec.empty()) ans.push_back(vec[0]);
            int c = s2[i] - 'a';
            if (pos[c].empty()) { printf("-1\n"); return 0; }
            vec.clear();
            for (int x : pos[c]) vec.push_back({x, 1}), vec.push_back({x, -1});
        } else {
            vec = nxt;
        }
    }
    ans.push_back(vec[0]);

    printf("%d\n", ans.size());
    for (pii p : ans) {
        if (p.second < 0) printf("%d %d\n", p.first, p.first + p.second + 1);
        else printf("%d %d\n", p.first, p.first + p.second - 1);
    }
    return 0;
}
