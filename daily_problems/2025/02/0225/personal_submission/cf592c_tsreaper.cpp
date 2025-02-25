#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, A, B; scanf("%lld%lld%lld", &X, &A, &B);
    if (A > B) swap(A, B);
    __int128 l = (__int128) A / gcd(A, B) * B;
    long long ans = X / l * A + min(X % l, (__int128) A - 1);
    long long g = gcd(ans, X);
    ans /= g; X /= g;
    printf("%lld/%lld\n", ans, X);
    return 0;
}
