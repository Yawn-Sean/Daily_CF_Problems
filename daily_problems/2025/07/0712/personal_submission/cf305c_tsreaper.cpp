#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    map<long long, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }
    for (auto it = mp.begin(); it != mp.end(); ) {
        if (it->second >= 2) mp[it->first + 1] += it->second / 2;
        it->second %= 2;
        if (it->second == 0) mp.erase(it++);
        else it++;
    }
    printf("%lld\n", prev(mp.end())->first + 1 - (long long) mp.size());
    return 0;
}
