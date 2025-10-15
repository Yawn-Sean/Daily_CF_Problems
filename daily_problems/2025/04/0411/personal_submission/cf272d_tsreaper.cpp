#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
long long ans;
unordered_map<int, unordered_map<int, int>> mp;

long long f[MAXN * 2 + 5], two[MAXN * 2 + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % m;
        a = a * a % m;
    }
    return y;
}

int main() {
    scanf("%d", &n);
    for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x][i]++;
    }
    scanf("%d", &m);

    f[0] = 1;
    for (int i = 1; i <= n * 2; i++) {
        int x = i, t = 0;
        for (; x % 2 == 0; x /= 2, t++);
        f[i] = f[i - 1] * x % m;
        two[i] = two[i - 1] + t;
    }

    ans = 1;
    for (auto &p1 : mp) {
        int t = 0, sm = 0;
        for (auto &p2 : p1.second) {
            if (p2.second == 2) t++;
            sm += p2.second;
        }
        ans = ans * f[sm] % m * power(2, two[sm] - t) % m;
    }
    printf("%lld\n", ans);
    return 0;
}
