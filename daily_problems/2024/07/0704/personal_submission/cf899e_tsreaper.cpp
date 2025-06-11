#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, ans, A[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    list<pii> lst;
    map<pii, list<pii>::iterator> mp;
    for (int i = 1, j = 1; i <= n; i++) if (i == n || A[i] != A[i + 1]) {
        int len = i - j + 1;
        pii p = pii(-len, j);
        lst.push_back(p);
        mp[p] = prev(lst.end());
        j = i + 1;
    }

    while (!mp.empty()) {
        ans++;
        pii p = mp.begin()->first;
        auto it = mp.begin()->second;
        mp.erase(mp.begin());
        if (it == lst.begin() || next(it) == lst.end() || A[prev(it)->second] != A[next(it)->second]) {
            lst.erase(it);
            continue;
        }
        mp.erase(*prev(it));
        mp.erase(*next(it));
        prev(it)->first += next(it)->first;
        mp[*prev(it)] = prev(it);
        lst.erase(next(it));
        lst.erase(it);
    }
    printf("%d\n", ans);
    return 0;
}
