#include <bits/stdc++.h>
#define MAXS ((int) 2e6)
using namespace std;

int n, m;
char ans[MAXS + 10], s[MAXS + 10];

int main() {
    scanf("%d", &n);
    set<int> st;
    while (n--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int k; scanf("%d", &k);
        while (k--) {
            int x; scanf("%d", &x);
            int r = x + len - 1;
            while (m < r) st.insert(++m);
            auto it = st.lower_bound(x);
            while (it != st.end()) {
                if (*it > r) break;
                ans[*it] = s[*it - x + 1];
                st.erase(it++);
            }
        }
    }
    for (auto it = st.begin(); it != st.end(); it++) ans[*it] = 'a';
    printf("%s\n", ans + 1);
    return 0;
}
