#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, R; scanf("%d%d", &n, &R);

    int ans = -1, best = n + 1;
    for (int i = 0; i <= R; i++) if (gcd(i, R) == 1) {
        int x = 0, y = 0, a = R, b = i;
        while (b > 0) {
            int t = a / b;
            x += t; y += t - 1;
            a %= b;
            swap(a, b);
        }
        if (x == n && y < best) ans = i, best = y;
    }

    if (ans == -1) { printf("IMPOSSIBLE\n"); return 0; }
    printf("%d\n", max(0, best - 1));
    vector<int> vec;
    int a = R, b = ans, now = 0;
    while (b > 0) {
        int t = a / b;
        for (int i = 1; i <= t; i++) vec.push_back(now);
        a %= b;
        swap(a, b);
        now ^= 1;
    }
    reverse(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++) vec[i] ^= 1;
    for (int x : vec) printf("%c", "TB"[x ^ vec[0]]);
    printf("\n");
    return 0;
}
