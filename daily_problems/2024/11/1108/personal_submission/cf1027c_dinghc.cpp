#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int INF = 0x3F3F3F3F;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            mp[x]++;
        }
        vector<int> a;
        for (auto& [x, k] : mp) {
            if (k > 3) {
                a.push_back(x);
                a.push_back(x);
            } else if (k > 1) {
                a.push_back(x);
            }
        }
        int m = a.size();
        array<int64, 4> ans {INF, 1, 0, 0};
        for (int i = 1; i < m; i++) {
            int64 nu = a[i - 1] * a[i - 1] + a[i] * a[i];
            int64 de = a[i - 1] * a[i];
            int64 g = gcd(nu, de);
            nu /= g;
            de /= g;
            if (nu * ans[1] < de * ans[0]) {
                ans[0] = nu;
                ans[1] = de;
                ans[2] = a[i - 1];
                ans[3] = a[i];
            }
        }
        printf("%d %d %d %d\n", ans[2], ans[2], ans[3], ans[3]);
    }
    return 0;
}

