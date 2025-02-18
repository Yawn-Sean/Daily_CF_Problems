#include <bits/stdc++.h>
#define MAXN 7000
using namespace std;

int n;
long long ans, A[MAXN + 10], B[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &B[i]);

    unordered_map<long long, vector<long long>> mp;
    for (int i = 1; i <= n; i++) mp[A[i]].push_back(B[i]);

    vector<long long> vec;
    for (auto &p : mp) if (p.second.size() > 1) {
        vec.push_back(p.first);
        for (long long x : p.second) ans += x;
    }
    for (auto &p : mp) if (p.second.size() == 1) {
        for (long long x : vec) if ((x & p.first) == p.first) { ans += p.second[0]; break; }
    }
    printf("%lld\n", ans);
    return 0;
}
