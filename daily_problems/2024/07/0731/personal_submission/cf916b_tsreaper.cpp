#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int K;
    scanf("%lld%d", &n, &K);

    map<int, int> mp;
    int cnt = 0;
    for (int p = 0; n; n >>= 1, p++) if (n & 1) mp[p] = 1, cnt++;
    if (cnt > K) { printf("No\n"); return 0; }

    while (true) {
        auto it = prev(mp.end());
        if (cnt + it->second <= K) {
            cnt += it->second;
            mp[it->first - 1] += it->second * 2;
            mp.erase(it);
        } else {
            int rem = K - cnt;
            mp[it->first - 1] += rem * 2;
            it->second -= rem;
            break;
        }
    }

    while (mp.size() > 1) {
        auto it = prev(prev(mp.end())), it2 = mp.begin();
        if (it->second <= 1) break;
        if (it == it2 && it->second <= 2) break;
        it->second -= 2;
        next(it)->second++;
        it2->second--;
        mp[it2->first - 1] += 2;
    }

    printf("Yes\n");
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
        for (int i = 1; i <= it->second; i++) printf("%d ", it->first);
    printf("\n");
    return 0;
}
