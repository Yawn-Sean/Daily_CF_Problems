#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<pair<int, int>, pair<pair<int, int>, pair<int, int>>> mp;
    auto upd = [&] (int a, int b, pair<int, int> cs) {
        if (a > b) swap(a, b);
        auto& [lp, sp] = mp[make_pair(a, b)];
        if (cs.first > lp.first) {
            swap(sp, lp);
            swap(lp, cs);
        } else if (cs.first > sp.first) {
            swap(sp, cs);
        }
    };
    for (int i = 1, a, b, c; i <= n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > c) swap(a, c);
        if (a == b && b == c) {
            upd(a, b, make_pair(c, i));
        } else if (a == b) {
            upd(a, b, make_pair(c, i));
            upd(a, c, make_pair(b, i));
        } else if (b == c) {
            upd(a, c, make_pair(b, i));
            upd(b, c, make_pair(a, i));
        } else {
            upd(a, b, make_pair(c, i));
            upd(a, c, make_pair(b, i));
            upd(b, c, make_pair(a, i));
        }
    }
    array<int, 3> ans{};
    for (auto& [kp, vp] : mp) {
        auto& [a, b] = kp;
        auto& [c1, c2] = vp;
        array<int, 3> tmp {min({a, b, c1.first + c2.first}), c1.second, c2.second};
        ans = max(ans, tmp);
    }
    if (ans[1] != 0 && ans[2] != 0) {
        printf("2\n");
        printf("%d %d\n", ans[1], ans[2]);
    } else if (ans[1] != 0) {
        printf("1\n");
        printf("%d\n", ans[1]);
    } else if (ans[2] != 0) {
        printf("1\n");
        printf("%d\n",  ans[2]);
    }
    return 0;
}

