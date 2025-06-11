#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, q;
set<int> app[MAXN + 5];
set<pii> st;

int main() {
    scanf("%d%d", &n, &q);
    int cnt = 0;
    while (q--) {
        int op, x; scanf("%d%d", &op, &x);
        if (op == 1) {
            cnt++;
            st.insert({cnt, x});
            app[x].insert(cnt);
        } else if (op == 2) {
            for (int y : app[x]) st.erase({y, x});
            app[x].clear();
        } else {
            while (!st.empty() && st.begin()->first <= x) {
                pii p = *(st.begin());
                st.erase(st.begin());
                app[p.second].erase(p.first);
            }
        }
        printf("%d\n", st.size());
    }
    return 0;
}
