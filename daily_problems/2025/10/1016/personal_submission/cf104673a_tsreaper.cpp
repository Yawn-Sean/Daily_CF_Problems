#include  <bits/stdc++.h>
#define MAGIC 2000
#define INF ((long long) 2e9)
using namespace std;

long long C[MAGIC + 5][MAGIC + 5];

int main() {
    unordered_map<int, int> mp;
    C[0][0] = 1;
    for (int i = 1; i <= MAGIC; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = min(C[i - 1][j - 1] + C[i - 1][j], INF);
    }
    for (int i = 0; i <= MAGIC; i++) for (int j = 0; j <= i; j++)
        if (!mp.count(C[i][j])) mp[C[i][j]] = i;
    
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);
        if (n == 1) { printf("1\n"); continue; }

        int a = n + 1;

        int head = 1, tail = n;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (1LL * mid * (mid - 1) / 2 >= n) tail = mid;
            else head = mid + 1;
        }
        int b = INF;
        if (1LL * head * (head - 1) / 2 == n) b = head + 1;

        int c = INF;
        if (mp.count(n)) c = mp[n] + 1;

        printf("%d\n", min({a, b, c}));
    }
    return 0;
}
