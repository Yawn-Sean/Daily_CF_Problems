#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<array<int, 2>> powers(n);
        for (int i = 0, x, t; i < n; i++) {
            scanf("%d %d", &x, &t);
            int p1 = 0, p2 = 0;
            if (t == 0) {
                p1 = x << 1;
                p2 = x;
            } else {
                p1 = x;
                p2 = x << 1;
            }
            powers[i] = {p1, p2};
        }
        vector<int> q[2]{};
        for (int i = 0, x, t; i < n; i++) {
            scanf("%d %d", &x, &t);
            q[t].push_back(x);
        }
        ranges::sort(powers, {}, [] (auto& p) {
            return -p[0];
        });
        ranges::sort(q[0], {}, [] (int x) {
            return -x;
        });
        bool failed = false;
        multiset<int> s;
        int j = 0;
        for (int i = 0; i < q[0].size(); i++) {
            while (j < n && powers[j][0] >= q[0][i]) {
                s.insert(powers[j++][1]);
            }
            if (s.empty()) {
                failed = true;
                break;
            }
            s.erase(s.begin());
        }
        if (failed) {
            printf("NO\n");
            continue;
        }
        ranges::sort(q[1], {}, [] (int x) {
            return -x;
        });
        while (j < n) {
            s.insert(powers[j++][1]);
        }
        for (int i = 0; i < q[1].size(); i++) {
            auto ite = s.lower_bound(q[1][i]);
            if (ite == s.end()) {
                failed = true;
                break;
            }
            s.erase(prev(s.end()));
        }
        if (failed) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

