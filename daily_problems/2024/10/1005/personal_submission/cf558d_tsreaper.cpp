#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<long long, long long> pll;

int main() {
    int H, q; scanf("%d%d", &H, &q);
    long long L = 1LL << (H - 1), R = (1LL << H) - 1;
    map<long long, int> mp;
    while (q--) {
        int h, t;
        long long l, r;
        scanf("%d%lld%lld%d", &h, &l, &r, &t);
        l = max(l, 1LL << (h - 1));
        r = min(r, (1LL << h) - 1);
        if (l > r) {
            if (t == 1) { printf("Game cheated!\n"); return 0; }
            else continue;
        }
        l <<= H - h;
        r <<= H - h;
        r |= (1LL << (H - h)) - 1;
        if (t == 1) {
            L = max(L, l);
            R = min(R, r);
        } else {
            mp[l]++;
            mp[r + 1]--;
        }
    }

    int now = 0;
    vector<pll> vec;
    if (mp.empty()) {
        vec.push_back({-INF, INF});
    } else {
        vec.push_back({-INF, mp.begin()->first - 1});
        for (auto it = mp.begin(); it != mp.end(); it++) {
            now += it->second;
            if (now == 0) {
                if (next(it) == mp.end()) vec.push_back({it->first, INF});
                else vec.push_back({it->first, next(it)->first - 1});
            }
        }
    }

    long long cnt = 0, cand;
    for (auto &p : vec) {
        long long l = max(L, p.first), r = min(R, p.second);
        if (l > r) continue;
        if (l == r) cand = l;
        cnt += r - l + 1;
    }
    if (cnt == 1) printf("%lld\n", cand);
    else if (cnt == 0) printf("Game cheated!\n");
    else printf("Data not sufficient!\n");
    return 0;
}
