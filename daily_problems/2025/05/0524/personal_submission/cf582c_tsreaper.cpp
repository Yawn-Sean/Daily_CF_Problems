#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

bool flag[MAXN + 5];

void gao(int g, vector<int> &vec) {
    memset(flag, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= g; i ++) {
        int mx = 0;
        for (int j = i; j <= n; j += g) mx = max(mx, A[j]);
        for (int j = i; j <= n; j += g) if (A[j] == mx) flag[j] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (flag[i]) cnt++;
    if (cnt == n) {
        ans += 1LL * vec.size() * n;
        return;
    }

    vector<int> segs;
    for (int i = 1, now = 0; i <= n; i++) {
        if (flag[i]) {
            now++;
            if (i == n || !flag[i + 1]) segs.push_back(now);
        } else {
            now = 0;
        }
    }
    if (flag[1] && flag[n]) segs[0] += segs.back(), segs.pop_back();
    sort(segs.begin(), segs.end());

    cnt = segs.size();
    long long sm = 0;
    for (int x : segs) sm += x;
    for (int i = 0, j = 0; i < vec.size(); i++) {
        while (j < segs.size() && segs[j] < vec[i]) {
            cnt--;
            sm -= segs[j];
            j++;
        }
        ans += sm - 1LL * (vec[i] - 1) * cnt;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_map<int, vector<int>> mp;
    for (int i = 1; i < n; i++) mp[gcd(n, i)].push_back(i);
    for (auto &p : mp) gao(p.first, p.second);
    printf("%lld\n", ans);
    return 0;
}
