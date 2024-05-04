#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];

int cnt[MAXN + 10];
multiset<int> ms;

void inc(int x) {
    int t = ++cnt[x];
    if (t > 1) ms.erase(ms.find(t - 1));
    ms.insert(t);
}

void dec(int x) {
    int t = --cnt[x];
    ms.erase(ms.find(t + 1));
    if (t > 0) ms.insert(t);
}

bool check() {
    if (ms.size() == 1) return true;
    if (*(ms.begin()) == 1) {
        auto it = next(ms.begin());
        if (*it == *prev(ms.end())) return true;
    }
    auto it = prev(ms.end());
    if (*(ms.begin()) == *prev(it) && *prev(it) + 1 == *it) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) inc(A[i]);
    for (int i = n; i > 0; i--) {
        if (check()) { printf("%d\n", i); return 0; }
        dec(A[i]);
    }
    return 0;
}
