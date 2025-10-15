#include <bits/stdc++.h>
 
using namespace std;
using int64 = long long;
constexpr int M = 1e9 + 7;
constexpr int N = 1e5;
char a[N + 1];

int64 fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= M;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % M;
        a = a * a % M;
    }
    return ans;
}

int64 inv(int a) {
    return a <= 1 ? a : M - static_cast<int64>(M / a) * inv(M % a) % M;
}

int main() {
    int k;
    scanf("%s%d", a, &k);
    int res1 = 0;
    int n = 0;
    for (; a[n] != '\0'; n++) {
        if (a[n] == '0' || a[n] == '5') {
            res1 = (res1 + fast_pow(2, n)) % M;
        }
    }
    int ans = (fast_pow(2, 1LL * n * k) - 1) % M * inv(fast_pow(2, n) - 1) % M * res1 % M;
    printf("%d\n", ans);
    return 0;
}

