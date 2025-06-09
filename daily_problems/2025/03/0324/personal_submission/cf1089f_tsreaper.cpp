#include <bits/stdc++.h>
#define MAXN ((int) 1e9)
#define MAXS ((int) 4e4)
using namespace std;

bool flag[MAXS + 5];
vector<int> prime;

int main() {
    for (int i = 2; i <= MAXS; i++) if (!flag[i]) {
        prime.push_back(i);
        for (int j = i * 2; j <= MAXS; j += i) flag[j] = true;
    }

    int n; scanf("%d", &n);
    vector<int> fac;
    int t = n;
    for (int p : prime) {
        if (p > t) break;
        if (t % p) continue;
        fac.push_back(p);
        while (t % p == 0) t /= p;
    }
    if (t > 1) fac.push_back(t);

    if (fac.size() < 2) { printf("NO\n"); return 0; }
    long long a = fac[1], b = fac[0], K = n / a / b;
    int x;
    for (x = 1; x < b; x++) if ((a * x + 1) % b == 0) break;
    int y = K * a - (a * x + 1) / b;
    printf("YES\n2\n%d %d\n%d %d\n", x, n / fac[1], y, n / fac[0]);
    return 0;
}
