#include <bits/stdc++.h>
#define MAXS ((int) 1e6)
using namespace std;

bool flag[MAXS + 5];
vector<int> prime;

int main() {
    for (int i = 2; i <= MAXS; i++) if (!flag[i]) {
        prime.push_back(i);
        for (int j = i * 2; j <= MAXS; j += i) flag[j] = true;
    }

    long long n; scanf("%lld", &n);
    long long s = sqrt(n);
    if (s * s == n) { printf("N\n"); return 0; }

    int x = 0, y = 0;
    for (int p : prime) {
        if (p > n) break;
        if (n % p == 0) {
            x++;
            while (n % p == 0) y++, n /= p;
        }
    }
    if (n > 1) x++, y++;

    if (x >= 2 && y >= 3) printf("N\n");
    else printf("Y\n");
    return 0;
}
