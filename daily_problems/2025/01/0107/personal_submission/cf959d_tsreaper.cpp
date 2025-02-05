#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAGIC ((int) 2e6)
#define MAXA ((int) 1e5 + 3)
using namespace std;

int n, A[MAXN + 5];

bool flag[MAGIC + 5];
set<int> prime;
vector<int> fac[MAXA + 5];

bool full;

bool check(int x) {
    for (int p : fac[x]) if (prime.count(p) == 0) return false;
    return true;
}

int gao(int x) {
    int y;
    if (full) {
        for (y = x; y <= MAXA; y++) if (check(y)) {
            for (int p : fac[y]) prime.erase(p);
            break;
        }
        if (y > MAXA) {
            auto it = prime.lower_bound(y);
            y = *it;
            prime.erase(it);
        }
        if (y > x) full = false;
    } else {
        y = *(prime.begin());
        prime.erase(prime.begin());
    }
    return y;
}

int main() {
    for (int i = 2; i <= MAGIC; i++) if (!flag[i]) {
        prime.insert(i);
        for (int j = i * 2; j <= MAGIC; j += i) flag[j] = true;
    }
    for (int i = 2; i <= MAXA; i++) if (fac[i].empty())
        for (int j = i; j <= MAXA; j += i) fac[j].push_back(i);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    full = true;
    for (int i = 1; i <= n; i++) printf("%d%c", gao(A[i]), "\n "[i < n]);
    return 0;
}
