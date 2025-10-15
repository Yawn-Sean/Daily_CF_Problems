#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, ans[MAXN + 5];

struct Seg {
    int l, r;
    unordered_set<int> st;
};

unordered_set<int> query(int l, int r) {
    printf("Q %d %d\n", l, r); fflush(stdout);
    unordered_set<int> ret;
    for (int i = l; i <= r; i++) {
        int x; scanf("%d", &x);
        ret.insert(x);
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    if (n == 1) {
        ans[1] = *(query(1, 1).begin());
    } else if (n == 2) {
        ans[1] = *(query(1, 1).begin());
        ans[2] = 3 - ans[1];
    } else if (n == 3) {
        ans[1] = *(query(1, 1).begin());
        ans[2] = *(query(2, 2).begin());
        ans[3] = 6 - ans[1] - ans[2];
    } else {
        vector<Seg> segs;
        auto st = query(1, (1 + n) / 2);
        segs.push_back({1, (1 + n) / 2, st});
        unordered_set<int> st2;
        for (int i = 1; i <= n; i++) if (st.count(i) == 0) st2.insert(i);
        segs.push_back({(1 + n) / 2 + 1, n, st2});

        while (!segs.empty()) {
            vector<Seg> nxt;
            for (int i = 0; i < segs.size(); i += 2) {
                int l = (segs[i].l + segs[i].r) / 2 + 1;
                int r = i + 1 < segs.size() ? (segs[i + 1].l + segs[i + 1].r) / 2 : segs[i].r;
                auto st = query(l, r);

                unordered_set<int> tmp[4];
                for (int x : segs[i].st) {
                    if (st.count(x)) tmp[1].insert(x);
                    else tmp[0].insert(x);
                }
                if (i + 1 < segs.size()) for (int x : segs[i + 1].st) {
                    if (st.count(x)) tmp[2].insert(x);
                    else tmp[3].insert(x);
                }

                nxt.push_back({segs[i].l, l - 1, tmp[0]});
                nxt.push_back({l, segs[i].r, tmp[1]});
                if (i + 1 < segs.size()) {
                    nxt.push_back({segs[i + 1].l, r, tmp[2]});
                    nxt.push_back({r + 1, segs[i + 1].r, tmp[3]});
                }
            }

            segs.clear();
            for (auto &seg : nxt) {
                if (seg.l == seg.r) { ans[seg.l] = *(seg.st.begin()); continue; }
                segs.push_back(seg);
            }
        }
    }

    printf("A");
    for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
    return 0;
}
