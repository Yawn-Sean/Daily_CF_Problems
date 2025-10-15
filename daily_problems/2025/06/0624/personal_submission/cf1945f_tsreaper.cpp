#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    multiset<int> ms1, ms2;
    long long sm = 0, ans1 = 0;
    int ans2 = 0;
    for (int i = 1; i <= n; i++) ms2.insert(A[i]);
    for (int i = 1; i <= n; i++) {
        while (ms1.size() < i && !ms2.empty()) {
            auto it = prev(ms2.end());
            ms1.insert(*it); sm += *it;
            ms2.erase(it);
        }
        long long t = *(ms1.begin()) * (long long) ms1.size();
        if (t > ans1) ans1 = t, ans2 = i;

        int x = A[B[i]];
        auto it = ms1.find(x);
        if (it != ms1.end()) ms1.erase(it), sm -= x;
        else ms2.erase(ms2.find(x));
    }
    printf("%lld %d\n", ans1, ans2);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
