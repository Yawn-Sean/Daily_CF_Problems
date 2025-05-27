#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    unordered_map<int, unordered_map<int, long long>> mp;
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        long long k, b; scanf("%lld%lld", &k, &b);
        if (k == 0) continue;
        if (k < 0) sm += k;
        bool flag = k * b < 0;
        long long g = gcd(abs(k), abs(b));
        if (flag) mp[abs(k) / g][-abs(b) / g] += abs(k);
        else mp[abs(k) / g][abs(b) / g] += abs(k);
    }
    vector<array<long long, 3>> vec;
    for (auto &p1 : mp) for (auto &p2 : p1.second) vec.push_back({p1.first, p2.first, p2.second});
    sort(vec.begin(), vec.end(), [&](array<long long, 3> &a, array<long long, 3> &b) {
        return -a[1] * b[0] < -b[1] * a[0];
    });

    vector<long long> tmp;
    tmp.push_back(sm);
    for (auto &arr : vec) {
        sm += arr[2];
        tmp.push_back(sm);
    }

    int ans = 0;
    for (int i = 1; i < tmp.size(); i++) if (tmp[i - 1] != tmp[i]) ans++;
    printf("%d\n", ans);
    return 0;
}
