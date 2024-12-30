#include <bits/stdc++.h>
using namespace std;

struct Ufs {
    vector<int> fa;
    Ufs(int n) {
        fa = vector<int>(n, -1);
    }

    int find(int x) {
        return (fa[x] < 0) ? x : (fa[x] = find(fa[x]));
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        fa[y] += fa[x];
        fa[x] = y;
    }

    int size(int x) {
        return -fa[find(x)];
    }
};

void work() {   
    int n, d; cin >> n >> d;

    Ufs ufs(n);
    multiset<int> mset;
    for (int i = 0; i < n; i ++) {
        mset.insert(1);
    }
    int free_cnt = 1;

    while (d --) {
        int a, b; cin >> a >> b;
        a --; b --;
        if (ufs.find(a) == ufs.find(b)) {
            free_cnt ++;
        } else {
            mset.erase(mset.find(ufs.size(a)));
            mset.erase(mset.find(ufs.size(b)));
            ufs.merge(a, b);
            mset.insert(ufs.size(a));
        }

        int ans = 0;
        auto siter = mset.rbegin();
        for (int i = 0 ; i < free_cnt; i ++) {
            ans += *siter;
            siter ++;
        }

        cout << ans - 1 << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}