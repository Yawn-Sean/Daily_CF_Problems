#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> l(m);
    for (auto& x : l) {
        scanf("%d", &x);
        x -= 1;
    }
    vector<int> vis(n + 1, 0);
    vector<int> a(n, -1);
    for (int i = 0; i < m - 1; i++) {
        int t;
        if (l[i + 1] > l[i]) {
            t = l[i + 1] - l[i];
        } else {
            t = l[i + 1] + n - l[i];
        }
        if (a[l[i]] != t && a[l[i]] != -1) {
            printf("-1\n");
            return 0;
        }
        a[l[i]] = t;
        vis[t] = 1;
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (st.find(a[i]) != st.end()) {
                printf("-1\n");
                return 0;
            }
            st.insert(a[i]);
        }
    }
    for (int i = 0, j = 1; i < n; i++) {
        if (a[i] == -1) {
            while (vis[j]) j += 1;
            a[i] = j++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

