#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
long long ans;

long long f[MAXN + 10];

int main() {
    scanf("%d%*d", &n);
    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        mp[x].push_back(y);
    }
    for (auto &p : mp) {
        sort(p.second.begin(), p.second.end(), greater<int>());
        long long sm = 0;
        for (int j = 0; j < p.second.size(); j++) {
            sm += p.second[j];
            f[j + 1] += max(sm, 0LL);
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}
