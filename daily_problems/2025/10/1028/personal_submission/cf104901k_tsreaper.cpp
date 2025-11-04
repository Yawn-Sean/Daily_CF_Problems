#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, ans;
long long K, A[MAXN + 10];

struct Magic {
    multiset<long long> st1, st2;
    long long sm1, sm2;

    Magic() {
        sm1 = 0; sm2 = 0;
    }

    void adjust() {
        int tot = st1.size() + st2.size();
        int a = tot / 2, b = tot - a;
        while (st1.size() < a) {
            long long t = *(st2.begin());
            st1.insert(t); sm1 += t;
            st2.erase(st2.begin()); sm2 -= t;
        }
        while (st2.size() < b) {
            long long t = *prev(st1.end());
            st2.insert(t); sm2 += t;
            st1.erase(prev(st1.end())); sm1 -= t;
        }
    }

    void add(long long x) {
        if (!st2.empty() && x >= *(st2.begin())) st2.insert(x), sm2 += x;
        else st1.insert(x), sm1 += x;
        adjust();
    }

    void del(long long x) {
        auto it = st1.find(x);
        if (it != st1.end()) st1.erase(it), sm1 -= x;
        else st2.erase(st2.find(x)), sm2 -= x;
        adjust();
    }

    long long query() {
        long long mid = *(st2.begin());
        return (st1.size() * mid - sm1) + (sm2 - st2.size() * mid);
    }
};

void solve() {
    scanf("%d%lld", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]), A[i] -= i;

    Magic magic;
    ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        magic.add(A[i]);
        while (j <= i && magic.query() > K) {
            magic.del(A[j]);
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
