#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &k, &n);
    vector<int> a(k + 1, 0);
    for (int i = 0, x; i < k; i++) {
        scanf("%d", &x);
        a[i + 1] = a[i] + x;
    }
    vector<int> b(n);
    for (auto& x : b) scanf("%d", &x);
    int ans = 0;
    unordered_set<int> init;
    for (int i = 1; i <= k; i++) {
        int x = b[0] - a[i];
        if (init.find(x) != init.end()) continue;
        init.insert(x);
        unordered_set<int> mp;
        for (int j = 1; j <= k; j++) {
            mp.insert(x + a[j]);
        }
        bool flg = true;
        for (auto& y : b) {
            if (mp.find(y) == mp.end()) {
                flg = false;
                break;
            }
        }
        if (flg) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}

