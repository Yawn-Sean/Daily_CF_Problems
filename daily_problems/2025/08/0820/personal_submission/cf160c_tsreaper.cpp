#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long K;
    scanf("%d%lld", &n, &K);
    
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }

    long long now = 0;
    for (auto it1 = mp.begin(); it1 != mp.end(); it1++) {
        long long nxt = now + 1LL * it1->second * n;
        if (nxt < K) {
            now = nxt;
            continue;
        }
        for (auto it2 = mp.begin(); it2 != mp.end(); it2++) {
            long long nxt = now + 1LL * it1->second * it2->second;
            if (nxt < K) {
                now = nxt;
                continue;
            }
            printf("%d %d\n", it1->first, it2->first);
            return 0;
        }
    }
    return 0;
}
