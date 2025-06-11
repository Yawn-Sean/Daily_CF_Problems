#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAXP 30
using namespace std;

int n, A[MAXN + 10];
map<int, int> mp;

bool check(int lim) {
    mp.clear();
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int p = MAXP - 1; p >= 0; p--) {
            int now = A[i] >> p;
            if (now > lim) break;
            t = now;
        }
        mp[t]++;
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) if (it->second > 1) {
        if (it->first == 1) return false;
        mp[it->first >> 1] += it->second - 1;
        it->second = 1;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++) tail = max(tail, A[i]);
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }

    check(head);
    for (auto &p : mp) printf("%d ", p.first);
    printf("\n");
    return 0;
}
